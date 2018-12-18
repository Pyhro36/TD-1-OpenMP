#!/bin/bash

CORES=$1
WIDTH=$2
HEIGHT=$3
FILE=$4

iterations=10
productLineVectMatTimeSum=0
productMatColumnVectTimeSum=0

OLDIFS="$IFS"
IFS=","

echo "Temps avec $CORES coeur(s) et des matrices de $WIDTH sur $HEIGHT" > $FILE
echo "Produit d'un vecteur-ligne par une matrice,Produit d'une matrice par un vecteur-colonne" >> $FILE

for ((i=0 ; iterations - $i ; i++))
do
	./out $CORES $WIDTH $HEIGHT > tmpResult
	read productLineVectMatTime productMatColumnVectTime < tmpResult
	let "productLineVectMatTimeSum=$productLineVectMatTimeSum + $productLineVectMatTime"
	let "productMatColumnVectTimeSum=$productMatColumnVectTimeSum + $productMatColumnVectTime"
	cat tmpResult >> $FILE
done

IFS="$OLDIFS"

echo "Moyenne : " >> $FILE

echo "scale=1;$productLineVectMatTimeSum/$iterations" | bc | tr -d "\n" >> $FILE
printf "," >> $FILE
echo "scale=1;$productMatColumnVectTimeSum/$iterations" | bc | tr -d "\n" >> $FILE

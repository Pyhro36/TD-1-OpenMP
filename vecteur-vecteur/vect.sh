#!/bin/bash

CORES=$1
LENGTH=$2
FILE=$3

iterations=10
sumAddTime=0
sumSumTime=0
sumProductTime=0 

OLDIFS="$IFS"
IFS=","

printf "Temps avec " > $FILE
printf $CORES >> $FILE
printf " coeur(s) et des vecteurs de " >> $FILE
printf $LENGTH >> $FILE
echo " termes" >> $FILE  
echo "Addition de deux vecteurs, Somme des termes d'un vecteur, Produit d'un vecteur par un scalaire" >> $FILE

for ((i=0 ; iterations - $i ; i++))
do
	./out $CORES $LENGTH > tmpResult
	read addTime sumTime productTime < tmpResult
	let "sumAddTime=$sumAddTime + $addTime"
	let "sumSumTime=$sumSumTime + $sumTime"
	let "sumProductTime=$sumProductTime + $productTime"
	cat tmpResult >> $FILE
done

IFS="$OLDIFS"

echo "Moyenne : " >> $FILE

echo "scale=1;$sumAddTime/$iterations" | bc | tr -d "\n" >> $FILE
printf "," >> $FILE
echo "scale=1;$sumSumTime/$iterations" | bc | tr -d "\n" >> $FILE
printf "," >> $FILE
echo "scale=1;$sumProductTime/$iterations" | bc | tr -d "\n" >> $FILE

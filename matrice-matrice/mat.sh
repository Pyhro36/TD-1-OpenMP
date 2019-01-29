#!/bin/bash

CORES=$1
M=$2
N=$3
P=$4
FILE=$5

iterations=10
productMatTimeSum=0

echo "Temps avec ${CORES} coeur(s) et des matrices de ${M} sur ${N} et ${N} sur ${P}" > ${FILE}
echo "Produit d'une matrice par une matrice" >> ${FILE}

for ((i=0 ; iterations - $i ; i++))
do
	productMatTime=$(./out ${CORES} ${M} ${N} ${P})
	let "productMatTimeSum=$productMatTimeSum + $productMatTime"
	echo ${productMatTime} >> ${FILE}
done

echo "Moyenne : " >> ${FILE}

echo "scale=1;$productMatTimeSum/$iterations" | bc | tr -d "\n" >> ${FILE}
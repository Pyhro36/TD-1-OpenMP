
iterations=10
sumAddTime=0
sumSumTime=0
sumProductTime=0 

OLDIFS="$IFS"
IFS=","

echo "Addition de deux vecteurs, Somme des termes d'un vecteur, Produit d'un vecteur par un scalaire" > $3

for ((i=0 ; iterations - $i ; i++))
do
	./out $1 $2 > tmpResult
	read addTime sumTime productTime < tmpResult
	let "sumAddTime=$sumAddTime + $addTime"
	let "sumSumTime=$sumSumTime + $sumTime"
	let "sumProductTime=$sumProductTime + $productTime"
	cat tmpResult >> $3
done

IFS="$OLDIFS"

echo "Moyenne : " >> $3

echo "scale=1;$sumAddTime/$iterations" | bc | tr -d "\n" >> $3
printf "," >> $3
echo "scale=1;$sumSumTime/$iterations" | bc | tr -d "\n" >> $3
printf "," >> $3
echo "scale=1;$sumProductTime/$iterations" | bc | tr -d "\n" >> $3

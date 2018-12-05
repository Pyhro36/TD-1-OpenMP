# TD-1-OpenMP

Manipulation de Matrices et de Vecteurs avec OpenMP

## 1.1 Vecteur-Vecteur

Dans le dossier vecteur-vecteur :

Le code de l'application qui manipule les vecteurs (addition terme à terme, somme des termes et mutliplication par un scalaire) est le fichier main_vect.cpp. Son header est le fichier main_vect.h

Pour le compiler, on a utilisé g++ :
`$ g++ -std=c++11 --openmp -o out main_vect.cpp`

Il en sort le fichier out-vect qui est l'exécutable. 
Ce programme s'éxecute de la façon suivante : 
`$ out nombre_de_threads_OpenMP nombre_de_termes_des_vecteurs`
Il donne en sortie dans cet ordre et séparés par des virgules le temps d'addition terme à terme de deux vecteurs aléatoires, le temps de somme des termes du premier vecteur et le temps du produit du premier vecteur avec un scalaire.

Le script vect.sh permet de lancer 10 itérations du programme, d'en enregistrer la sortie dans un fichier CSV, et de faire la moyenne des temps de chacune des trois opérations.
**ATTENTION** ce script a été codé en considérant que le programme se nomme out
Il se lance comme suit :
`$ vect.sh nombre_de_threads_OpenMP nombre_de_termes_des_vecteurs nom_du_fichier_CSV`

Les fichiers vect_NonParallelise_1_dataset.csv et vect_n_coeurs_n_datasets.csv sont les résultats.
1_datasets signifie 100 000 000 termes, 2_datasets, 200 000 000 termes etc.

## 1.2 Matrice-Vecteur


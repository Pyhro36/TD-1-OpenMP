# TD-1-OpenMP
Manipulation de Matrices et de Vecteurs avec OpenMP

## 2.1 Vecteur-Vecteur

Dans le dossier vecteur-vecteur :

Le code de l'application qui manipule les vecteurs (addition terme à terme, somme des termes et mutliplication par un scalaire) est le fichier `main_vect.cpp`.
Son header est le fichier `main_vect.h`.

Pour le compiler, on a utilisé g++ :
`$ g++ -fopenmp -o out main_vect.cpp`
sauf pour le cas où on veut tester le code séquentiellement, où dans ce cas la ligne 30 (`omp_set_num_threads(coresNb);`) est commentée et la compilation est faite sans l'option `-fopenmp`.

Il en sort le fichier `out` qui est l'exécutable. 
Ce programme s'éxecute de la façon suivante : 
`$ out nombre_de_threads_OpenMP nombre_de_termes_des_vecteurs`
Il donne en sortie dans cet ordre et séparés par des virgules le temps d'addition terme à terme de deux vecteurs aléatoires, le temps de somme des termes du premier vecteur et le temps du produit du premier vecteur avec un scalaire.

Le script `vect.sh` permet de lancer 10 itérations du programme, d'en enregistrer la sortie dans un fichier CSV, et de faire la moyenne des temps de chacune des trois opérations.
**ATTENTION** ce script a été codé en considérant que le programme se nomme `out`.
Il se lance comme suit :
`$ vect.sh nombre_de_threads_OpenMP nombre_de_termes_des_vecteurs nom_du_fichier_CSV`

Les fichiers `vect_non_parallelise_1_dataset.csv` et `vect_n_coeurs_n_datasets.csv` sont les résultats.
`1_datasets` signifie 100 000 000 termes, `2_datasets`, 200 000 000 termes etc.

Le document `resultats et graphes.ods` permet de générer les graphes de passage à l'échelle faible et fort à partir des résultats.

## 2.2 Matrice-Vecteur

Dans le dossier matrice-vecteur :

Le code de l'application qui manipule les mulitplications de vecteurs avec des matrices (produit d'un vecteur-ligne par une matrice et produit d'une matrice par un vecteur-colonne) est le fichier `main_vect_mat.cpp`. 
Son header est le fichier `main_vect_mat.h`.

Pour le compiler, on a utilisé g++ :
`$ g++ -fopenmp -o out main_vect_mat.cpp`
sauf pour le cas où on veut tester le code séquentiellement, où dans ce cas la ligne 30 (`omp_set_num_threads(coresNb);`) est commentée et la compilation est faite sans l'option `-fopenmp`.

Il en sort le fichier out qui est l'exécutable. 
Ce programme s'éxecute de la façon suivante : 
`$ out nombre_de_threads_OpenMP nombre_de_colonnes_de_la_matrice nombre_de_lignes_de_la_matrice`
Il donne en sortie dans cet ordre et séparés par des virgules le temps de produit d'un vecteur-ligne aléatoire par la matrice (aléatoire) et le temps de produit de la matrice par un vecteur-colonne aléatoire.

Le script `vect_mat.sh` permet de lancer 10 itérations du programme, d'en enregistrer la sortie dans un fichier CSV, et de faire la moyenne des temps de chacune des trois opérations.
**ATTENTION** ce script a été codé en considérant que le programme se nomme `out`
Il se lance comme suit :
`$ vect_mat.sh nombre_de_threads_OpenMP nombre_de_colonnes_de_la_matrice nombre_de_lignes_de_la_matrice nom_du_fichier_CSV`

Les fichiers `vect_mat_non_parallelise_1_dataset.csv` et `vect_mat_n_coeurs_n_datasets.csv` sont les résultats.
`1_dataset` signifie une matrice de 100 par 1 000 000, `2_datasets`, 200 par 1 000 000 etc.

Le document `resultats et graphes.ods` permet de générer les graphes de passage à l'échelle faible et fort à partir des résultats

## 2.3 Matrice-Matrice

Dans le dossier matrice-matrice :

Le code de l'application qui manipule les mulitplications de matrices est le fichier `main_vect_mat.cpp`.
Son header est le fichier `main_vect_mat.h`.

Pour le compiler, on a utilisé g++ :
`$ g++ -fopenmp -o out main_mat.cpp`
sauf pour le cas où on veut tester le code séquentiellement, où dans ce cas la ligne 31 (`omp_set_num_threads(coresNb);`) est commentée et la compilation est faite sans l'option `-fopenmp`.

Il en sort le fichier `out` qui est l'exécutable. 
Ce programme s'éxecute de la façon suivante : 
`$ out nombre_de_threads_OpenMP nombre_de_colonnes_de_la_matrice_1 nombre_de_lignes_de_la_matrice_1 nombre_de_lignes_de_la_matrice_2`
Il donne en sortie dans le temps de produit de la matrice 1 par la matrice 2 (aléatoires).

Le script `mat.sh` permet de lancer 10 itérations du programme, d'en enregistrer la sortie dans un fichier CSV, et de faire la moyenne des temps de chacune des trois opérations.
**ATTENTION** ce script a été codé en considérant que le programme se nomme `out`.
Il se lance comme suit :
`$ mat.sh nombre_de_threads_OpenMP nombre_de_colonnes_de_la_matrice_1 nombre_de_lignes_de_la_matrice_1 nombre_de_lignes_de_la_matrice_2 nom_du_fichier_CSV`

Les fichiers `mat_non_parallelise_1_dataset.csv` et `mat_n_coeurs_n_datasets.csv` sont les résultats.
`1_dataset` signifie des matrices de 200 par 1000 et 1000 par 500, `2_datasets`, 200 par 1000 et 100 par 500 etc.

Le document `resultats et graphes.ods` permet de générer les graphes de passage à l'échelle faible et fort à partir des résultats

## Conclusion

Le document `Rapport-TD1-OpenMP-pllefebvre.{odt|pdf}` est le rendu final, avec tous les graphes et les éléments d'analyse qui en découlent.

La totalité du TP peut être retrouvée sur le GitHub public : https://github.com/Pyhro36/TD-1-OpenMP.

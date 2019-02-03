#ifndef MAIN_MAT_H
#define MAIN_MAT_H

/**
 * Affichage des termes d'une matrice de int
 */
void displayIntMat(int **mat, int width, int height);

/**
 * Affichage des termes d'une matrice de long
 */
void displayLongMat(long **mat, int width, int height);

/**
 * Produit matricel, la matrice ret doit etre entierement allouee pour recevoir le resultat
 */ 
void productMat(int **mat1, int **mat2, long **ret, int m, int n, int p);


#endif // MAIN_MAT_H

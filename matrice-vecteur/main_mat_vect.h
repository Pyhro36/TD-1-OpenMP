#ifndef MAIN_MAT_VECT_H
#define MAIN_MAT_VECT_H

/**
 * Affichage des termes d'un vecteur de int
 */
void displayInt(int *vec, int length);

/**
 * Affichage des termes d'un vecteur de long
 */
void displayLong(long *vec, int length);

/**
 * Affichage des termes d'une matrice de int
 */
void displayIntMat(int **mat, int width, int height);

/**
 * Affichage des termes d'une matrice de long
 */
void displayLongMat(long **mat, int width, int height);

/**
 * Produit d'un vecteur ligne par une matrice, le vecteur ret doit etre initialise pour recevoir le resultat
 */ 
void productLineVectMat(int *vec, int **mat, long *ret, int width, int height);

/**
 * Produit d'une matrice par un vecteur colonne, le vecteur ret doit etre initialise pour recevoir le resultat
 */
void productMatColumnVect(int **mat, int *vec, long *ret, int width, int height);

#endif // MAIN_MAT_VECT_H

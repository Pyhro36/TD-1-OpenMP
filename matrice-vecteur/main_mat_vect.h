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
 * Affichage des termes d'un vecteur de double
 */
void displayDouble(double *vec, int length);

/**
 * Somme des termes d'un vecteur
 */
long sum(int *vec, int length);

/**
 * Somme de deux vecteurs, le vecteur ret doit etre initialise pour recevoir le resultat
 */
void add(int *vec1, int *vec2, long *ret, int length);

/**
 * Produit d'un vecteur par un double, le vecteur ret doit etre initialise pour recevoir le resultat
 */ 
void product(int *vec, double factor, double *ret, int length);

#endif // MAIN_MAT_VECT_H

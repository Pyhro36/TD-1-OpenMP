#ifndef MAIN_H
#define MAIN_H

/**
 * Affichage des termes d'un vecteur
 */
void display(int *vec, int length);

/**
 * Somme des termes d'un vecteur
 */
long sum(int *vec, int length);

/**
 * Somme de deux vecteurs, le vecteur ret doit etre initialise pour recevoir le resultat
 */
void add(int *vec1, int *vec2, int *ret, int length);

/**
 * Produit d'un vecteur par un double, le vecteur ret doit etre initialise pour recevoir le resultat
 */ 
void product(int *vec, double factor, double *ret, int length);

#endif // MAIN_H

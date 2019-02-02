#include "main_vect.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

#define NB_MAX 100

int main(int argc, char **argv)
{
    int i;

    // instanciation des vecteurs
    int *vector1 = new int[NB_MAX];
    int *vector2 = new int[NB_MAX];

    // remplissage des vecteurs
    srand(time(NULL));

    for (i = 0; i < NB_MAX; i++)
    {
        vector1[i] = rand();
        vector2[i] = rand();
    }

    // affichage des vecteurs
    displayInt(vector1, NB_MAX);
    displayInt(vector2, NB_MAX);

    long *result = new long[NB_MAX];

    // addition des deux vecteurs
    add(vector1, vector2, result, NB_MAX);
    displayLong(result, NB_MAX);
    delete[] result;

    // somme des termes du premier vecteur
    long sumResult = sum(vector1, NB_MAX);
    std::cout << sumResult << std::endl << std::endl;

    // liberation memoire
    delete[] vector1;
    delete[] vector2;

    return 0;
}

void displayInt(int *vec, int length)
{
    int i;
    for (i = 0; i < length; i++)
        std::cout << vec[i] << std::endl;

    std::cout << std::endl;
}

void displayLong(long *vec, int length)
{
    int i;
    for (i = 0; i < length; i++)
        std::cout << vec[i] << std::endl;

    std::cout << std::endl;
}

long sum(int *vec, int length)
{
    int i;
    long sum = 0;

    for (i = 0; i < length; i++)
    {
        sum += vec[i];
    }

    return sum;
}

void add(int *vec1, int *vec2, long *ret, int length)
{
    int i;

    for (i = 0; i < length; i++)
    {
        ret[i] = (long)(vec1[i]) + (long)(vec2[i]);
    }
}

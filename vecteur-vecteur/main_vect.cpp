#include "main_vect.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <omp.h>

#define NB_MAX 100

int main(int argc, char **argv)
{
    int i, nbMax;
    int nbCore = 1;

    if(argc < 3)
    {
        std::cout << "usage : app_name number_of_cores array_size" << std::endl;
    }
    else
    {
        nbCore = std::stoi(argv[1]);
        nbMax = std::stoi(argv[2]);
    }

    omp_set_num_threads(nbCore);

    // instanciation des vecteurs
    int *vector1 = new int[nbMax];
    int *vector2 = new int[nbMax];

    // remplissage des vecteurs
    srand(time(NULL));

    for (i = 0; i < nbMax; i++)
    {
        vector1[i] = rand();
        vector2[i] = rand();
    }

    // affichage des vecteurs
    displayInt(vector1, nbMax);
    displayInt(vector2, nbMax);

    long *result = new long[nbMax];

    // addition des deux vecteurs
    add(vector1, vector2, result, nbMax);
    displayLong(result, nbMax);
    delete[] result;

    // somme des termes du premier vecteur
    long sumResult = sum(vector1, nbMax);
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

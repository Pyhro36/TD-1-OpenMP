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
#include "main_vect.h"

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

    // liberation memoire
    delete[] vector1;
    delete[] vector2;

    return 0;
}

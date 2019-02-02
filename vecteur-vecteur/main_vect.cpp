#include "main_vect.h"

#define NB_MAX 100

int main(int argc, char **argv)
{
    int *vector1 = new int[NB_MAX];
    int *vector2 = new int[NB_MAX];

    srand(time(NULL));

    for (i = 0; i < nbMax; i++)
    {
        vector1[i] = rand();
        vector2[i] = rand();
    }
   
    delete[] vector1;
    delete[] vector2;

    return 0;
}

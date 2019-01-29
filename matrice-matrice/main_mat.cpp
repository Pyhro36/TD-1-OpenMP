#include "main_mat.h"

#include <iostream>
#include <chrono>
#include <ctime>
#include <cstdlib>
#include <omp.h>

#define NB_MAX 100

using namespace std::chrono;

int main(int argc, char **argv)
{
    int i, j;
    int m, n, p;

    int coresNb = 1;

    if (argc < 4)
    {
    	std::cout << "usage : app_name number_of_cores M N P (for matrices MxN . NxP)" << std::endl;
    	exit(0);
    }

    coresNb = std::stoi(argv[1]);
    m = std::stoi(argv[2]);
    n = std::stoi(argv[3]);
    p = std::stoi(argv[4]);

    omp_set_num_threads(coresNb);

    // instanciation des matrices
    int **matrix1 = new int*[m];

    for (i = 0; i < m; i++)
    {
        matrix1[i] = new int[n];
    }

    int **matrix2 = new int*[n];

    for (i = 0; i < n; i++)
    {
        matrix2[i] = new int[p];
    }

    // remplissage des données aléatoires
    srand(time(NULL));

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            matrix1[i][j] = rand() % 1000;
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < p; j++)
        {
            matrix2[i][j] = rand() % 1000 ;
        }
    }

    // affichage des donnees en entree pour les tests
//    displayIntMat(matrix1, m, n);
//    displayIntMat(matrix2, n, p);

    // instanciation de la matrice de resultats
    long **result = new long*[m];

    for (int i = 0; i < m; i++)
    {
        result[i] = new long[p];
    }

    // produit de la matrice 1 par la matrice 2
	high_resolution_clock::time_point start = high_resolution_clock::now();
    productMat(matrix1, matrix2, result, m, n, p);
    high_resolution_clock::time_point end = high_resolution_clock::now();
    nanoseconds time_duration = duration_cast<nanoseconds>(end - start);
    std::cout << time_duration.count();
//    displayLongMat(result, m, p);

    // liberation memoire

    for (i = 0; i < m; i++)
    {
        delete[] result[i];
        delete[] matrix1[i];
    }

    delete[] matrix1;
    delete[] result;

    for (i = 0; i < n; i++)
    {
        delete[] matrix2[i];
    }

    delete[] matrix2;

    return 0;
}

void displayIntMat(int **mat, int width, int height)
{
    int i, j;
    for (i = 0; i < width; i++)
    {
        for (j = 0; j < height; j++)
        {
            std::cout << mat[i][j] << " ";
        }

        std::cout << std::endl;
    }

    std::cout << std::endl;
}

void displayLongMat(long **mat, int width, int height)
{
    int i, j;
    for (i = 0; i < width; i++)
    {
        for (j = 0; j < height; j++)
        {
            std::cout << mat[i][j] << " ";
        }

        std::cout << std::endl;
    }

    std::cout << std::endl;
}

void productMat(int **mat1, int **mat2, long **ret, int m, int n, int p)
{
    int i, j, k;

    #pragma omp parallel for collapse(2) shared(ret, mat1, mat2, m, n, p) private(i, j, k)
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < p; j++)
        {
            ret[i][j] = 0;

            // La reduction ne fonctionne pas car OpenMP ne reconnait pas ret[i][j] comme valide
            // #pragma omp parallel for reduction(+:ret[i][j]) shared(i, j, mat1, mat2, n) private(k)
            for (k = 0; k < n; k++)
            {
                ret[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}
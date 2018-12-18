#include "main_mat_vect.h"

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

    int coresNb = 1;
    int width, height;

    if (argc < 4)
    {
    	std::cout << "usage : app_name number_of_cores width height" << std::endl;
    	exit(0);
    }

    coresNb = std::stoi(argv[1]);
    width = std::stoi(argv[2]);
    height = std::stoi(argv[3]);

     omp_set_num_threads(coresNb);

    // instanciation des matrice et vecteurs
    int *lineVector = new int[width];
    int *columnVector = new int[height];
    int **matrix = new int*[width];

    for (i = 0; i < width; i++)
    {
        matrix[i] = new int[height];
    }

    // remplissage des données aléatoires
    srand(time(NULL));

    for (i = 0; i < height; i++)
    {
        columnVector[i] = rand() % 1000 ;
    }

    for (i = 0; i < width; i++)
    {
        lineVector[i] = rand() % 1000;

        for (j = 0; j < height; j++)
        {
            matrix[i][j] = rand() % 1000 ;
        }
    }

    // affichage des donnees en entree pour les tests
    // displayInt(lineVector, width);
    // displayInt(columnVector, height);
    // displayIntMat(matrix, width, height);

	// produit d'un vecteur ligne par une matrice
    long *columnResult = new long[height];
	high_resolution_clock::time_point start = high_resolution_clock::now();
    productLineVectMat(lineVector, matrix, columnResult, width, height);
    high_resolution_clock::time_point end = high_resolution_clock::now();
    nanoseconds time_duration = duration_cast<nanoseconds>(end - start);
    std::cout << time_duration.count() << ",";
    // displayLong(columnResult, height);
    delete[] columnResult;

    // produit d'une matrice par un vecteur colonne
    long *lineResult = new long[width];
    start = high_resolution_clock::now();
    productMatColumnVect(matrix, columnVector, lineResult, width, height);
    end = high_resolution_clock::now();
    time_duration = duration_cast<nanoseconds>(end - start);
    std::cout << time_duration.count() << std::endl;
    // displayLong(lineResult, width);
    delete[] lineResult;

    // liberation memoire
    delete[] lineVector;
    delete[] columnVector;

    for (i = 0; i < width; i++)
    {
        delete[] matrix[i];
    }

    delete[] matrix;

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

void productLineVectMat(int *vec, int **mat, long *ret, int width, int height)
{
    int i, j;

    #pragma omp parallel for shared(ret, vec, mat, width, height) private(i, j)
    for (i = 0; i < height; i++)
    {
        ret[i] = 0;

        #pragma omp parallel for reduction(+:ret[i]) shared(i, vec, mat, width) private(j)
        for (j = 0; j < width; j++)
        {
            ret[i] += vec[j] * mat[j][i];
        }
    }
}

void productMatColumnVect(int **mat, int *vec, long *ret, int width, int height)
{
    int i, j;

    #pragma omp parallel for shared(ret, vec, mat, width, height) private(i, j)
    for (i = 0; i < width; i++)
    {
        ret[i] = 0;

        #pragma omp parallel for reduction(+:ret[i]) shared(i, vec, mat, height) private(j)
        for (j = 0; j < height; j++)
        {
            ret[i] += vec[j] * mat[i][j];
        }
    }
}
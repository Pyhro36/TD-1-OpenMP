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
    	std::cout << "usage : app_name number_of_cores array_size" << std::endl;
    }
    else
    {
	    coresNb = std::stoi(argv[1]);
    	width = std::stoi(argv[2]);
    	height = std::stoi(argv[3]);
    }

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

    displayInt(lineVector, width);
    displayInt(columnVector, height);
    displayIntMat(matrix, width, height);

	// produit d'un vecteur ligne par une matrice
    long *columnResult = new long[height];
	high_resolution_clock::time_point start = high_resolution_clock::now();
    productLineVectMat(lineVector, matrix, columnResult, width, height);
    high_resolution_clock::time_point end = high_resolution_clock::now();
    nanoseconds time_duration = duration_cast<nanoseconds>(end - start);
    std::cout << time_duration.count() << ",";
    displayLong(columnResult, height);
    delete[] columnResult;

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

void displayLong(long *vec, int length) {
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

    //// Cette parallelisation n'est pas bonne, elle provoque un Segmentation fault
/*
    #pragma omp parallel shared(ret, vec, mat, width, height) private(i, j)
    {
        #pragma omp for
        for (i = 0; i < height; i++)
        {
            ret[i] = 0;
        }

        #pragma omp for collapse(2) reduction(+:ret[i])
        for (i = 0; i < height; i++)
        {
            for (j = 0; j < width; j++)
            {
                ret[i] += vec[j] * mat[j][i];
            }
        }
    }
*/
    //// Voici la solution simplifiée proposée
    #pragma omp parallel shared(ret, vec, mat, width, height) private(i, j)
    {
        #pragma omp for
        for (i = 0; i < height; i++)
        {
            ret[i] = 0;
            for (j = 0; j < width; j++)
            {
                ret[i] += vec[j] * mat[j][i];
            }
        }
    }
}

void productMatColumnVect(int **mat, int *vec, long *ret, int width, int height)
{

}
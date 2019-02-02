#include "main_vect.h"

#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <omp.h>

#define NB_MAX 100

using namespace std::chrono;

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
    // displayInt(vector1, nbMax);
    // displayInt(vector2, nbMax);

    long *result = new long[nbMax];

    // addition des deux vecteurs
    high_resolution_clock::time_point start = high_resolution_clock::now();
    add(vector1, vector2, result, nbMax);
    high_resolution_clock::time_point end = high_resolution_clock::now();
    nanoseconds time_duration = duration_cast<nanoseconds>(end - start);
    std::cout << "add time : " << time_duration.count() << std::endl;
    // displayLong(result, nbMax);
    delete[] result;

    // somme des termes du premier vecteur
    high_resolution_clock::time_point sumStart = high_resolution_clock::now();
    long sumResult = sum(vector1, nbMax);
    high_resolution_clock::time_point sumEnd = high_resolution_clock::now();
    time_duration = duration_cast<nanoseconds>(sumEnd - sumStart);
    std::cout << "sum time : " << time_duration.count() << std::endl;
    // std::cout << sumResult << std::endl << std::endl;

    // produit du premier vecteur par un double
    double *productResult = new double[nbMax];
    double factor = (((double)rand()) / RAND_MAX) * 1000;
    high_resolution_clock::time_point prodStart = high_resolution_clock::now();
    product(vector1, factor, productResult, nbMax);
    high_resolution_clock::time_point prodEnd = high_resolution_clock::now();
    time_duration = duration_cast<nanoseconds>(prodEnd - prodStart);
    std::cout << "product time : " << time_duration.count() << std::endl;
    // displayDouble(productResult, nbMax);

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

void displayDouble(double *vec, int length)
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

    #pragma omp parallel for reduction(+:sum)
    for (i = 0; i < length; i++)
    {
        sum += vec[i];
    }

    return sum;
}

void add(int *vec1, int *vec2, long *ret, int length)
{
    int i;

    #pragma omp parallel for shared(ret, vec1, vec2)
    for (i = 0; i < length; i++)
    {
        ret[i] = (long)(vec1[i]) + (long)(vec2[i]);
    }
}

void product(int *vec, double factor, double *ret, int length)
{
    int i;

    #pragma omp parallel for shared(factor, vec, ret)
    for (i = 0; i < length; i++)
    {
        ret[i] = factor * vec[i];
    }
}

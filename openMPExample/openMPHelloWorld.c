#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
int main(int argc, char **argv)
{
    if (argc < 3)
    {
        fprintf(stderr,"Not enough arguments given!\n");
        return EXIT_FAILURE;
    }
 	
    
    double length = atof(argv[1]);
    int pieces = atoi(argv[2]);
    
    const double h = length / pieces;
    const double x_0 = 0.0;
    
    omp_set_num_threads(4);

    double pi;
    double startZeit, endZeit;

    int i;
    double sum = 0.0;

    startZeit = omp_get_wtime();

#pragma omp parallel for reduction(+: sum) schedule(static)
    for (i = 0; i < pieces; ++i)
    {
        double x = x_0 + i * h + h/2;
        sum += sqrt(1 - x*x);
    }

    endZeit = omp_get_wtime();

    pi = sum * h * 4.0;

    printf("omp_get_max_threads(): %d\n", omp_get_max_threads());
    printf("time: %f\n", endZeit - startZeit);
    printf("pi ~ %.50f\n", pi);

    return 0;
}	
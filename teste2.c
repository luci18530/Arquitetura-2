#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 500

int main(int argc, char const *argv[])
{
    int stop = 0;
    int k, j, i;
    clock_t startantes, endantes, startdepois, enddepois;
    double tempoantes, tempodepois;
    int x[5000][100];
    /* Antes*/
    startantes = clock();
    for (k = 0; k < 100; k = k+1)
        for (j = 0; j < 100; j = j+1)
            for (i = 0; i < 5000; i = i+1)
                x[i][j] = 2 * x[i][j];
                printf("\n");
    endantes = clock();
    /* Depois*/
    startdepois = clock();
    for (k = 0; k < 100; k = k+1)
        for (i = 0; i < 5000; i = i+1)
            for (j = 0; j < 100; j = j+1)
                x[i][j] = 2 * x[i][j];
                printf("\n");
    enddepois = clock();

    // diferença entre o tempo inicial e o tempo final
    tempoantes = (double)(endantes - startantes) / CLOCKS_PER_SEC;
    printf("Tempo gasto antes: %lf segundos \n", tempoantes);
    tempodepois = (double)(enddepois - startdepois) / CLOCKS_PER_SEC;
    printf("Tempo gasto depois: %lf segundos \n", tempodepois);

    return 0;
}

// PERMUTA DE LOOPS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 30

int main(int argc, char const *argv[])
{
    int i, j, pause;
    clock_t startantes, endantes, startdepois, enddepois;
    double tempoantes, tempodepois;

    int N = SIZE-1;
    int a[SIZE][SIZE];
    int b[SIZE][SIZE];
    int c[SIZE][SIZE];
    int d[SIZE][SIZE];
    /* Antes*/
    startantes = clock();
    for (i = 0; i < N; i = i+1)
        for (j = 0; j < N; j = j+1){
            a[i][j] = (b[i][j]) * (c[i][j]);
            printf("\n");}
    for (i = 0; i < N; i = i+1)
        for (j = 0; j < N; j = j+1) {
            d[i][j] = (a[i][j]) + (c[i][j]);
            printf("\n"); }
    endantes = clock();
    /* Depois */
    startdepois = clock();
    for (i = 0; i < N; i = i+1)
        for (j = 0; j < N; j = j+1)
            { a[i][j] = b[i][j] * c[i][j];
            d[i][j] = a[i][j] + c[i][j];
            printf("\n");}
    enddepois = clock();

    // diferença entre o tempo inicial e o tempo final
    tempoantes = (double)(endantes - startantes) / CLOCKS_PER_SEC;
    printf("Tempo gasto antes: %lf segundos \n", tempoantes);
    tempodepois = (double)(enddepois - startdepois) / CLOCKS_PER_SEC;
    printf("Tempo gasto depois: %lf segundos \n", tempodepois);
    scanf("%d", &pause);
    return 0;
}

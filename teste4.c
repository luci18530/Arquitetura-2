// PERMUTA DE LOOPS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 30
#define min(x, y) (((x) < (y)) ? (x) : (y))
// blocagem
int main(int argc, char const *argv[])
{
    int i, j, pause;
    clock_t startantes, endantes, startdepois, enddepois;
    double tempoantes, tempodepois;

    int N = SIZE-1;
    int r,k = 0;
    int y[SIZE][SIZE];
    int z[SIZE][SIZE];
    int x[SIZE][SIZE];
    // B fator de blocagem
    int B = 3;
    /* Antes*/
    startantes = clock();
   /* Antes */
    for (i = 0; i < N; i = i+1)
        for (j = 0; j < N; j = j+1){
            r = 0;
            for (k = 0; k < N; k = k+1){
                r = r + y[i][k]*z[k][j];
                printf("\n");}
            x[i][j] = r;
    }
    endantes = clock();
    /* Depois */
    startdepois = clock();
    /* Depois */
    for (int jj = 0; jj < N; jj = jj+B)
        for (int kk = 0; kk < N; kk = kk+B)
            for (i = 0; i < N; i = i+1)
                for (j = jj; j < min(jj+B-1,N); j = j+1){
                    r = 0;
                    for (k = kk; k < min(kk+B-1,N); k = k+1) {
                        r = r + y[i][k]*z[k][j];
                        printf("\n");
                    }
                    x[i][j] = x[i][j] + r;
    }
    enddepois = clock();

    // diferença entre o tempo inicial e o tempo final
    tempoantes = (double)(endantes - startantes) / CLOCKS_PER_SEC;
    printf("Tempo gasto antes: %lf segundos \n", tempoantes);
    tempodepois = (double)(enddepois - startdepois) / CLOCKS_PER_SEC;
    printf("Tempo gasto depois: %lf segundos \n", tempodepois);
    scanf("%d", &pause);
    return 0;
}

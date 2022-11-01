#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 500

int main(int argc, char const *argv[])
{
    int stop = 0;
    clock_t startantes, endantes, startdepois, enddepois;
    double tempoantes, tempodepois;
    startantes = clock();
    /* Antes: 2 arrays sequenciais */
    int val[SIZE];
    int key[SIZE];

    for (int i = 0; i < SIZE; i++) {
        val[i] = i;
        key[i] = 6*i;
        printf("\n");
    }

    endantes = clock();



    startdepois = clock();
    /* Depois: 1 array de estruturas */
    struct merge {
        int val;
        int key;
    };
    struct merge merged_array[SIZE];

    for (int i = 0; i < SIZE; i++) {
        merged_array[i].val = i;
        merged_array[i].key = 6*i;
        printf("\n");
    }

    enddepois = clock();

    // diferença entre o tempo inicial e o tempo final
    tempoantes = (double)(endantes - startantes) / CLOCKS_PER_SEC;
    printf("Tempo gasto antes: %lf segundos \n", tempoantes);
    tempodepois = (double)(enddepois - startdepois) / CLOCKS_PER_SEC;
    printf("Tempo gasto depois: %lf segundos \n", tempodepois);
    scanf("%d", &stop);

    return 0;
}

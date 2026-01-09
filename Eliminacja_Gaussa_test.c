#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Eliminacja_Gaussa.h"

void drukujMacierz(double **macierz, int wiersze, int kolumny) {
    for (int i = 0; i < wiersze; i++) {
        for (int j = 0; j < kolumny; j++) {
            printf("%8.2f ", macierz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int r, c;
    printf("Podaj liczbe wierszy i kolumn: ");
    if (scanf("%d %d", &r, &c) != 2) return 1;

    double **macierz = (double **)malloc(r * sizeof(double *));
    for (int i = 0; i < r; i++) {
        macierz[i] = (double *)malloc(c * sizeof(double));
    }

    printf("Wprowadz elementy macierzy:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%lf", &macierz[i][j]);
        }
    }

    printf("\nMacierz wejsciowa:\n");
    drukujMacierz(macierz, r, c);

    eliminacjaGaussa(macierz, r, c);

    printf("\nMacierz po eliminacji Gaussa:\n");
    drukujMacierz(macierz, r, c);

    return 0;
}
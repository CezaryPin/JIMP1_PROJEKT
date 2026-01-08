#include <stdlib.h>
#include <stdio.h>

double *podstawienie(double** maciez, int n){
    double *wynik=calloc(n,sizeof(double));
    double tmp;
    for(int i=0;i<n;i++){
        tmp=maciez[i][i+1];   //przyjmuje ostatnią wartość z danego wiersza (b_i)
        for(int j=0;j<i;j++)
            tmp-=maciez[i][i-j]*wynik[i-j+1];  //odejmuje a_j *x_j od b_i
        tmp/=maciez[i][0];    //b_i/a_i =x_i jeśli wszystkie inne wartości już wyzerowane
        wynik[i]=tmp;
    }
    return wynik;
}

void printTable(double *table,int n){ //pomocnicze do wypisania wektora
    printf("[ ");
    for(int i=0;i<n;i++){
        printf("%f ",table[i]);
    }
    printf("]");
}


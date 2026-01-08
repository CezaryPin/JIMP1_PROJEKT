void eliminacjaGaussa(double **macierz, int wiersze, int kolumny) {
    int n = wiersze;
    
    for (int i = 0; i < n && i < kolumny - 1; i++) {
        
       
        int maxwiersz = i;
        for (int k = i + 1; k < n; k++) {
            if (fabs(macierz[k][i]) > fabs(macierz[maxwiersz][i])) {
                maxwiersz = k;
            }
        }

        
        double *temp = macierz[maxwiersz];
        macierz[maxwiersz] = macierz[i];
        macierz[i] = temp;
        
        if (fabs(macierz[i][i]) < 1e-9) {
            continue; 
        }

        
        for (int k = i + 1; k < n; k++) {
            double czynnik = macierz[k][i] / macierz[i][i];
            for (int j = i; j < kolumny; j++) {
                macierz[k][j] -= czynnik * macierz[i][j];
            }
        }
    }
}

void odwrocMacierz(double **macierz, int wiersze) {
    for (int i = 0; i < wiersze / 2; i++) {
        double *temp = macierz[i];
        macierz[i] = macierz [wiersze - 1 - i];
        macierz [wiersze - 1 - i] = temp;
    }
}
#include <stdio.h>
#include <stdlib.h>

int main() 
{
    FILE *fin = fopen("upper.txt", "r");
    FILE *fout = fopen("full.txt", "w");
    if (!fin || !fout) 
    {
        printf("Ошибка открытия файлов.\n");
        return 1;
    }

    int n; 
    fscanf(fin, "%d", &n);
    double val;
    double M[100][100];

    for (int i = 0; i < n; i++) 
    {
        for (int j = i; j < n; j++) 
        {
            fscanf(fin, "%lf", &M[i][j]);
        }
        for (int j = 0; j < i; j++) 
        {
            M[i][j] = 0;
        }
    }

    fprintf(fout, "%d\n", n);
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++)
        {
            fprintf(fout, "%.2lf ", M[i][j]);
        }
        fprintf(fout, "\n");
    }

    fclose(fin);
    fclose(fout);
    return 0;
}

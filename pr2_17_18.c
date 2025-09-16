#include <stdio.h>
#include <stdlib.h>

int readMatrix(FILE *f, double M[100][100], int *rows, int *cols) 
{
    if (fscanf(f, "%d", cols) != 1) 
    {
        printf("Ошибка: не удалось считать количество столбцов.\n");
        return 0;
    }

    *rows = 0;
    while (1) 
    {
        int count = 0;
        for (int j = 0; j < *cols; j++) 
        {
            if (fscanf(f, "%lf", &M[*rows][j]) != 1) 
            {
                if (j == 0) 
                {
                    return 1;
                } else 
                {
                    printf("Ошибка: строка %d содержит меньше элементов, чем указано.\n", *rows + 1);
                    return 0;
                }
            }
            count++;
        }
        (*rows)++;
    }
    return 1;
}

int main() 
{
    FILE *f1 = fopen("mat1.txt", "r");
    FILE *f2 = fopen("mat2.txt", "r");
    FILE *fout = fopen("res_17_18.txt", "w");
    if (!f1 || !f2 || !fout) 
    {
        printf("Ошибка открытия файлов.\n");
        return 1;
    }

    double A[100][100], B[100][100], C[100][100];
    int rows1, cols1, rows2, cols2;

    if (!readMatrix(f1, A, &rows1, &cols1)) return 1;
    if (!readMatrix(f2, B, &rows2, &cols2)) return 1;

    if (cols1 != rows2) 
    {
        printf("Матрицы несовместимы: %d (столбцов в 1-й) != %d (строк во 2-й)\n", cols1, rows2);
        return 1;
    }

    for (int i = 0; i < rows1; i++) 
    {
        for (int j = 0; j < cols2; j++) 
        {
            C[i][j] = 0;
            for (int k = 0; k < cols1; k++) 
            {
                C[i][j] += A[i][k] * B[k][j];
            }
            fprintf(fout, "%.2lf ", C[i][j]);
        }
        fprintf(fout, "\n");
    }

    fclose(f1);
    fclose(f2);
    fclose(fout);
    printf("Результат записан в res_17_18.txt\n");
    return 0;
}

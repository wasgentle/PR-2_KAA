#include <stdio.h>
#include <stdlib.h>

int main() 
{
    FILE *fin = fopen("num_15.txt", "r");
    FILE *fout = fopen("res_15.txt", "w");
    if (!fin || !fout)
    {
        printf("Ошибка открытия файла.\n");
        return 1;
    }

    double prev, cur;
    int len = 1;

    if (fscanf(fin, "%lf", &prev) != 1) 
    {
        printf("Файл пуст.\n");
        return 1;
    }

    while (fscanf(fin, "%lf", &cur) == 1) 
    {
        if (cur < prev) 
        {
            len++;
        } 
        else 
        {
            if (len > 1) fprintf(fout, "%d ", len);
            len = 1;
        }
        prev = cur;
    }
    if (len > 1) fprintf(fout, "%d ", len);

    fclose(fin);
    fclose(fout);
    return 0;
}

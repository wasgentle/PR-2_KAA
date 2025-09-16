#include <stdio.h>
#include <stdlib.h>

long filesize(FILE *f) 
{
    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    fseek(f, 0, SEEK_SET);
    return size;
}

int main()
{
    char *names[3] = {"first.txt", "second.txt", "third.txt"};

    FILE *files[3];
    long sizes[3];

    for (int i = 0; i < 3; i++) 
    {
        files[i] = fopen(names[i], "rb");
        if (!files[i]) 
        {
            printf("Ошибка открытия файла %s.\n", names[i]);
            return 1;
        }
        sizes[i] = filesize(files[i]);
        fclose(files[i]);
    }

    int min_i = 0, max_i = 0;
    for (int i = 1; i < 3; i++) 
    {
        if (sizes[i] < sizes[min_i]) min_i = i;
        if (sizes[i] > sizes[max_i]) max_i = i;
    }

    FILE *fmin = fopen(names[min_i], "rb");
    FILE *fmax = fopen(names[max_i], "wb");
    if (!fmin || !fmax) 
    {
        printf("Ошибка открытия файлов для копирования.\n");
        return 1;
    }

    int c;
    while ((c = fgetc(fmin)) != EOF) 
    {
        fputc(c, fmax);
    }

    fclose(fmin);
    fclose(fmax);

    printf("Файл %s заменен содержимым %s\n", names[max_i], names[min_i]);
    return 0;
}

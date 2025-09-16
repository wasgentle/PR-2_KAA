#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() 
{
    FILE *fin = fopen("in_14.txt", "r");
    FILE *fout = fopen("out_14.txt", "w");
    if (!fin || !fout)
    
    {
        printf("Ошибка открытия файла.\n");
        return 1;
    }

    int c, count = 0;
    while ((c = fgetc(fin)) != EOF)
    {
        if (c == '\n') continue;
        fputc(c, fout);
        count++;

        if (c == '.') 
        {
            fputc('\n', fout);
            count = 0;
        }
        else if (count == 60) 
        {
            fputc('\n', fout);
            count = 0;
        }
    }
    fclose(fin);
    fclose(fout);

    printf("Готово! Результат в out.txt\n");

    return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//vraci delimetr
char delimetr(char** string)
{
    char* key1   = "-d";
    char del;

    if (strcmp(string[1], key1) == 0)
    {
        del = *string[2];
        return del;
    } else
    {
        del = ' ';
        return del;
    }
}

//delka retezce
int str_len(char* mas, char delim)
{
    int cell = 1;
    int str_len = 0;
    for (int i = 0; mas[i] != EOF && mas[i] != '\n'; ++i)
    {
        if (mas[i] == delim)
            ++cell;
    }

    int i = 0;
    for (int j = 0; j < cell; ++j)
    {
        str_len = 0;
        while (mas[i] != delim && mas[i] != EOF && mas[i] != '\n')
        {
            ++str_len;
            ++i;

            if(str_len >= 100)
            {
                fprintf(stderr, "ERROR: the line in the cell is too long\n");
                exit(1);
            }
        }
        ++i;
    }
    return 0;
}

//vytiskne massiv (just print)
void jpr(char* mas)
{
    for (int i = 0; mas[i] != EOF; i++)
    {
        printf("%c", mas[i]);

        if (mas[i] == '\n')
            break;
    }
}

//vlozi radek tabulky pred uvedeny radek
void irow(int arg, char* mas, int string_now, char delim)
{
    int i = 0;
    int column = 1;
    for (; mas[i] != EOF && mas[i] != '\n'; ++i)
    {
        if (mas[i] == delim)
            ++column;
    }

    if ((arg == string_now) && arg > 0)
    {
        for (int j = 0; j < column; ++j)
        {
            printf("%c", delim);
        }
        printf("\n");
        jpr(mas);
    } else
    {
        jpr(mas);
    }
}

//prida novy radek tabulky na konec tabulky
void arow(char* mas, int last_str)
{
    int n;

    for (n = 0; mas[n] != EOF; n++)
    {
        printf("%c", mas[n]);

        if (mas[n] == '\n')
            break;
    }

    if (last_str == 1 )
    {
        printf("\n");
    }
}

//odstrani uvedeny radek
void drow(int arg, char* mas, int string_now)
{
    if ((arg == string_now) && arg > 0)
    {

    } else
    {
        jpr(mas);
    }
}

//odstrani uvedene radky
void drows(int arg1, int arg2, char* mas, int string_now)
{
    if (arg1 <= string_now && arg2 >= string_now && arg1 > 0 && arg2 > 0)
    {

    } else
    {
        jpr(mas);
    }
}

//vlozi prazdny sloupec pred uvedeny sloupec
void icol(int col_we_need, char* mas, char delim)
{
    int column = 1;

    for(int i = 0; mas[i] != EOF; ++i)
    {
        if(col_we_need == column)
        {
            printf("%c", delim);
            ++column;
        }

        printf("%c", mas[i]);

        if(mas[i] == delim)
            ++column;

        if(mas[i] == '\n')
            break;
    }
}

//prida prazdny sloupec za posledni sloupec
void acol(char* mas, char delim)
{
    for(int i = 0; mas[i] != EOF; ++i)
    {
        if(mas[i] == '\n')
        {
            printf("%c", delim);
        }

        printf("%c", mas[i]);

        if(mas[i] == '\n')
            break;
    }
}

//odstrani uvedeny sloupec
void dcol(int col_we_need, char* mas, char delim)
{
    int column = 1;
    int end = 0;
    int j = 0;
    int counter = 0;

    while (counter < col_we_need)
    {
        for (; mas[j] != EOF && mas[j] != '\n' && mas[j] != delim; ++j)
        {

        }
        ++counter;
        if (mas[j] == delim)
            ++j;
    }
    if (mas[j] == '\n' || mas[j] == EOF)
    {
        end = 1;
    }

    for(int i = 0; mas[i] != EOF; ++i)
    {
        if(col_we_need == column)
        {
            for (;mas[i] != delim && mas[i] != '\n' && mas[i] != EOF; ++i)
            {

            }
            if (mas[i] == '\n')
            {
                printf("\n");
            }
        }

        if(col_we_need != column)
        {
            if (mas[i] ==delim && column + 1 == col_we_need && end == 1)
            {

            } else
                printf("%c", mas[i]);
        }

        if(mas[i] == delim)
            ++column;

        if(mas[i] == '\n')
        {
            break;
        }
    }
}

//odstrani uvedene sloupci
void dcols(int col_start, int col_end, char* mas, char delim)
{
    int column = 1;
    int i = 0;
    int j = 0;
    int counter = 0;
    int end =0;

    while (counter < col_end)
    {
        for (; mas[j] != EOF && mas[j] != '\n' && mas[j] != delim; ++j)
        {

        }
        ++counter;
        if (mas[j] == delim)
            ++j;
    }

    if (mas[j] == '\n' || mas[j] == EOF)
    {
        end = 1;
    }

    for (; mas[i] != EOF; ++i)
    {
        if (col_start <= column && col_end >= column)
        {
            for (; mas[i] != delim && mas[i] != EOF && mas[i] != '\n'; ++i)
            {

            }
            if (mas[i] == '\n')
                printf("\n");
        } else
        {
            if (mas[i] ==delim && column + 1 == col_start && end == 1)
            {

            } else
                printf("%c", mas[i]);
        }

        if(mas[i] == delim)
            ++column;

        if(mas[i] == '\n')
        {
            break;
        }
    }
}

//do bunky v uvedenem sloupci nastavi uvedeny retezec
void cset(int col_we_need, char* str, char* mas, char delim)
{
    int column = 1;

    for(int i = 0; mas[i] != EOF; ++i)
    {
        if(col_we_need == column)
        {
            printf("%s", str);
            ++column;
            for (; mas[i] != delim && mas[i] != '\n' && mas[i] != EOF; ++i)
            {

            }
            printf("%c", mas[i]);
        } else
            {
                printf("%c", mas[i]);
            }

        if(mas[i] == delim)
            ++column;

        if(mas[i] == '\n')
            break;
    }
}

//retezec v uvedenem sloupci prevede na mala pismena
void tlower(int col_we_need, char* mas, char delim)
{
    int column = 1;
    int differ = 'z' - 'Z';

    for(int i = 0; mas[i] != EOF; ++i)
    {
        if(col_we_need == column)
        {
            if(mas[i] >= 'A' && mas[i] <= 'Z')
            {
                printf("%c", mas[i] + differ);
            } else
            {
                printf("%c", mas[i]);
            }
        } else
            {
                printf("%c", mas[i]);
            }

        if(mas[i] == delim)
            ++column;

        if(mas[i] == '\n')
            break;
    }
}

//retezec v uvedemen sloupci prevede na velka pismena
void tUpper(int col_we_need, char* mas, char delim)
{
    int column = 1;
    int differ = 'z' - 'Z';

    for(int i = 0; mas[i] != EOF; ++i)
    {
        if(col_we_need == column)
        {
            if(mas[i] >= 'a' && mas[i] <= 'z')
            {
                printf("%c", mas[i] - differ);
            } else
            {
                printf("%c", mas[i]);
            }
        } else{
            printf("%c", mas[i]);
        }

        if(mas[i] == delim)
            ++column;

        if(mas[i] == '\n')
            break;
    }
}

//v uvedenem sloupci zaokrouhli cislo na cele cislo
void roundF(int col_we_need, char* mas, char delim)
{
    int column = 1;

    for(int i = 0; mas[i] != EOF; ++i)
    {
        if(col_we_need == column)
        {
            if((mas[i] >= '0' && mas[i] <= '9'))
            {
                while ((mas[i] >= '0' && mas[i] <= '9') && mas[i+1] != '.' && mas[i+1] != ',')
                {
                    printf("%c", mas[i]);
                    ++i;
                }

                if ((mas[i] >= '0' && mas[i] <= '9') && (mas[i+1] == '.' || mas[i+1] == ','))
                {
                    if (mas[i+2] >= '0' && mas[i+2]<= '9')
                    {
                        if (mas[i+2] >= '5' && mas[i+2]<= '9')
                        {
                            printf("%c", mas[i]+1);
                            i = i+2;
                            for (;mas[i] >= '0' && mas[i] <= '9'; ++i)
                            {

                            }
                            --i;
                        } else
                        {
                            printf("%c", mas[i]);
                            i = i+2;
                            for (;mas[i] >= '0' && mas[i] <= '9'; ++i)
                            {

                            }
                            --i;
                        }
                    } else
                    {

                    }
                } else
                {
                    printf("%c", mas[i]);
                }
            }else
            {
                printf("%c", mas[i]);
            }

        } else
            {
                printf("%c", mas[i]);
            }

        if(mas[i] == delim)
            ++column;

        if(mas[i] == '\n')
            break;
    }
}

//odstrani desetinou cast cisla v ukazanem sloupci
void intF(int col_we_need, char* mas, char delim)
{
    int column = 1;

    for(int i = 0; mas[i] != EOF; ++i)
    {
        if(col_we_need == column)
        {
            if((mas[i] >= '0' && mas[i] <= '9'))
            {
                while (mas[i] >= '0' && mas[i] <= '9')
                {
                    printf("%c", mas[i]);
                    ++i;
                }

                if (mas[i] == '.')
                {
                    ++i;
                    for (;mas[i] >= '0' && mas[i] <= '9'; ++i)
                    {

                    }
                }
                --i;
            }else
                {
                    printf("%c", mas[i]);
                }

        } else
            {
                printf("%c", mas[i]);
            }

        if(mas[i] == delim)
            ++column;

        if(mas[i] == '\n')
            break;
    }
}

//prepise obsah bunek v ukazanem sloupci hodnotami z ulazaneho sloupce
void copyF(int col1, int col2, char* mas, char delim)
{
    int column = 1;
    char masDop[100];

    for(int i = 0; mas[i] != EOF; ++i)
    {
        if(col1 == column)
        {
            int j = 0;
            for(; mas[i] != EOF || mas[i] != delim || mas[i] != '\n'; ++j, ++i)
            {
                masDop[j] = mas[i];
                if (mas[i] == delim || mas[i] == '\n'){
                    ++column;
                    break;
                }
            }
            masDop[j] = mas[i];
        }

        if(mas[i] == delim)
            ++column;

        if(mas[i] == '\n')
            continue;
    }

    column = 1;

    for(int i = 0; mas[i] != EOF; ++i)
    {
        if(col2 == column)
        {
            int j = 0;
            for(; masDop[j] != EOF && masDop[j] != delim && masDop[j] != '\n'; ++j)
            {
                printf("%c", masDop[j]);
                if (masDop[j] == delim || masDop[j] == '\n')
                {
                    break;
                }
            }

            for(; mas[i] != EOF || mas[i] != delim || mas[i] != '\n'; ++i)
            {
                if (mas[i] == delim || mas[i] == '\n')
                {
                    break;
                }
            }

            printf("%c", mas[i]);
            ++column;
        } else{
            printf("%c", mas[i]);
        }

        if(mas[i] == delim)
            ++column;

        if(mas[i] == '\n')
            break;
    }
}

//zameni hodnoty bunek v ukazanych sloupcich
void swapF(int col1, int col2, char* mas, char delim)
{
    int column = 1;
    char masDop1[100];
    char masDop2[100];

    for(int i = 0; mas[i] != EOF; ++i)
    {
        if(col1 == column)
        {
            int j = 0;
            for(; mas[i] != EOF || mas[i] != delim || mas[i] != '\n'; ++j, ++i)
            {
                masDop1[j] = mas[i];
                if (mas[i] == delim|| mas[i] == '\n'){
                    ++column;
                    break;
                }
            }
            masDop1[j] = mas[i];
        }

        if(mas[i] == delim)
            ++column;

        if(mas[i] == '\n')
            continue;
    }

    column = 1;

    for(int i = 0; mas[i] != EOF; ++i)
    {
        if(col2 == column)
        {
            int j = 0;
            for(; mas[i] != EOF || mas[i] != delim || mas[i] != '\n'; ++j, ++i)
            {
                masDop2[j] = mas[i];
                if (mas[i] == delim || mas[i] == '\n'){
                    ++column;
                    break;
                }
            }
            masDop2[j] = mas[i];
        }

        if(mas[i] == delim)
            ++column;

        if(mas[i] == '\n')
            continue;
    }

    column = 1;

    for(int i = 0; mas[i] != EOF; ++i)
    {
        if (col1 == column)
        {
            int j = 0;
            for (; masDop2[j] != EOF && masDop2[j] != delim && masDop2[j] != '\n'; ++j)
            {
                printf("%c", masDop2[j]);
                if (masDop2[j] == delim || masDop2[j] == '\n')
                {
                    break;
                }
            }

            for (; mas[i] != EOF || mas[i] != delim || mas[i] != '\n'; ++i)
            {
                if (mas[i] == delim || mas[i] == '\n')
                {
                    break;
                }
            }

            printf("%c", mas[i]);
        } else
            {
                if (col2 == column)
                {
                    int j = 0;

                    for (; masDop1[j] != EOF && masDop1[j] != delim && masDop1[j] != '\n'; ++j)
                    {
                        printf("%c", masDop1[j]);

                        if (masDop1[j] == delim || masDop1[j] == '\n')
                        {
                            ++column;
                            break;
                        }
                    }

                    for (; mas[i] != EOF || mas[i] != delim || mas[i] != '\n'; ++i)
                        {
                            if (mas[i] == delim || mas[i] == '\n')
                            {
                                break;
                            }
                        }

                    printf("%c", mas[i]);

                } else
                {
                    printf("%c", mas[i]);
                }
            }

        if(mas[i] == delim)
            ++column;

        if(mas[i] == '\n')
            break;
    }
}

//presune ukazany sloupec pred ukazany
void moveF(int col1, int col2, char* mas, char delim)
{
    int column = 1, nKa = 0;
    char masDop[100];

    int all_col = 1;
    for (int i = 0; mas[i] != EOF && mas[i] != '\n'; ++i)
    {
        if (mas[i] == delim)
        {
            ++all_col;
        }

        if (mas[i] == '\n')
            break;
    }

    for(int i = 0; mas[i] != EOF; ++i)
    {
        if(col1 == column)
        {
            int j = 0;
            for(; mas[i] != EOF || mas[i] != delim || mas[i] != '\n'; ++j, ++i)
            {
                masDop[j] = mas[i];
                if (mas[i] == delim || mas[i] == '\n'){
                    ++column;
                    break;
                }
            }
        }

        if(mas[i] == delim)
            ++column;

        if(mas[i] == '\n')
            continue;
    }

    column = 1;

    for(int i = 0; mas[i] != EOF; ++i)
    {
        if (col2 == column)
        {
            int j = 0;

            for (; masDop[j] != EOF && masDop[j] != delim && masDop[j] != '\n'; ++j)
            {
                printf("%c", masDop[j]);
            }

            printf("%c", delim);

            for (; mas[i] != EOF && mas[i] != delim && mas[i] != '\n'; ++i)
            {
                printf("%c", mas[i]);
                if (mas[i] == delim || mas[i] == '\n')
                {
                    break;
                }
            }

            if (masDop[j] == '\n')
            {
                ++nKa;
            }
        }

        if (col1 == (column))
        {
            for (; mas[i] != EOF && mas[i] != delim && mas[i] != '\n'; ++i)
            {
                if (mas[i] == delim || mas[i] == '\n')
                {
                    break;
                }
            }
        } else
        {
            for (; mas[i] != EOF && mas[i] != delim && mas[i] != '\n'; ++i)
            {
                printf("%c", mas[i]);
                if (mas[i] == delim || mas[i] == '\n')
                {
                    break;
                }
            }

            if (mas[i] == delim && nKa != 0 && column + 1 == all_col)
            {

            } else
            {
                printf("%c", mas[i]);
            }
        }

        if(mas[i] == delim)
            ++column;

        if(mas[i] == '\n')
            break;
    }
    if (nKa != 0)
        printf("\n");
}

//vrati pocet symbolu
int num_of_signs(char* mas)
{
    int i = 0;
    for (; mas[i] != '\0' ; ++i)
    {

    }
    return (i);
}

//sablona pro zpracovani fonkci rows. 2 uvedene argumenty
void dopRows2(char* ar1, char* ar2, char* ar3, char* ar4, char* ar5, char* mas, int col_now, char delim)
{
    char* csetV = "cset";
    char* copyV = "copy";
    char* swapV = "swap";
    char* moveV = "move";
    char* dcolsV = "dcols";

    char* key = "-";
    int col_start, col_end;

    col_start = atoi(ar1);
    col_end = atoi(ar2);

    if (col_start <= col_now && col_end >= col_now)
    {
        if (strcmp(ar3, csetV) == 0)
        {
            cset(atoi(ar4),ar5, mas, delim);
        }
        else if (strcmp(ar3, copyV) == 0)
        {
            copyF(atoi(ar4),atoi(ar5), mas, delim);
        }
        else if (strcmp(ar3, swapV) == 0)
        {
            swapF(atoi(ar4),atoi(ar5), mas, delim);
        }
        else if (strcmp(ar3, moveV) == 0)
        {
            moveF(atoi(ar4),atoi(ar5), mas, delim);
        }
        else if (strcmp(ar3, dcolsV) == 0)
        {
            dcols(atoi(ar4),atoi(ar5), mas, delim);
        }

    } else
    {
        if (col_start <= col_now && ((strcmp(ar2, key) == 0)) && (strcmp(ar1, key) != 0))
        {
            if (strcmp(ar3, csetV) == 0)
            {
                cset(atoi(ar4),ar5, mas, delim);
            }
            else if (strcmp(ar3, copyV) == 0)
            {
                copyF(atoi(ar4),atoi(ar5), mas, delim);
            }
            else if (strcmp(ar3, swapV) == 0)
            {
                swapF(atoi(ar4),atoi(ar5), mas, delim);
            }
            else if (strcmp(ar3, moveV) == 0)
            {
                moveF(atoi(ar4),atoi(ar5), mas, delim);
            }
            else if (strcmp(ar3, dcolsV) == 0)
            {
                dcols(atoi(ar4),atoi(ar5), mas, delim);
            }
        } else
        {
            if ((strcmp(ar1, key) == 0) && (strcmp(ar2, key) == 0))
            {
                int i = 0;
                for (; mas[i] != EOF && mas[i] != '\n'; ++i)
                {

                }

                if (mas[i] == EOF)
                {

                }

                if (mas[i] == '\n')
                {
                    for (i = 0; mas[i] != '\n'; i++)
                    {
                        printf("%c", mas[i]);
                    }

                    printf("\n");
                }

            } else
            {
                jpr(mas);
            }
        }
    }
}

//sablona pro zpracovani fonkci rows. 1 uvedeny argument
void dopRows1(char* ar1, char* ar2, char* ar3, char* ar4, char* mas, int col_now, char delim)
{
    char* icolV = "icol";
    char* dcolV = "dcol";

    char* tolowerV = "tolower";
    char* toupperV = "toupper";
    char* roundV = "round";
    char* intV = "int";

    char* key = "-";
    int col_start, col_end;
    col_start = atoi(ar1);
    col_end = atoi(ar2);

    if (col_start <= col_now && col_end >= col_now)
    {
        if (strcmp(ar3, icolV) == 0)
        {
            icol(atoi(ar4), mas, delim);
        }
        else if (strcmp(ar3, dcolV) == 0)
        {
            dcol(atoi(ar4), mas, delim);
        }
        else if (strcmp(ar3, tolowerV) == 0)
        {
            tlower(atoi(ar4), mas, delim);
        }
        else if (strcmp(ar3, toupperV) == 0)
        {
            tUpper(atoi(ar4), mas, delim);
        }
        else if (strcmp(ar3, roundV) == 0)
        {
            roundF(atoi(ar4), mas, delim);
        }
        else if (strcmp(ar3, intV) == 0)
        {
            intF(atoi(ar4), mas, delim);
        }

    } else
    {
        if (col_start <= col_now && ((strcmp(ar2, key) == 0)) && (strcmp(ar1, key) != 0))
        {
            if (strcmp(ar3, icolV) == 0)
            {
                icol(atoi(ar4), mas, delim);
            }
            else if (strcmp(ar3, dcolV) == 0)
            {
                dcol(atoi(ar4), mas, delim);
            }
            else if (strcmp(ar3, tolowerV) == 0)
            {
                tlower(atoi(ar4), mas, delim);
            }
            else if (strcmp(ar3, toupperV) == 0)
            {
                tUpper(atoi(ar4), mas, delim);
            }
            else if (strcmp(ar3, roundV) == 0)
            {
                roundF(atoi(ar4), mas, delim);
            }
            else if (strcmp(ar3, intV) == 0)
            {
                intF(atoi(ar4), mas, delim);
            }
        } else
        {
            if ((strcmp(ar1, key) == 0) && (strcmp(ar2, key) == 0))
            {
                int i = 0;
                for (; mas[i] != EOF && mas[i] != '\n'; ++i)
                {

                }

                if (mas[i] == '\n')
                {
                    for (i = 0; mas[i] != EOF; i++)
                    {
                        printf("%c", mas[i]);

                        if (mas[i] == '\n')
                            break;
                    }
                }

                if (mas[i] == EOF)
                {

                }

                if (mas[i] == '\n')
                {
                    for (i = 0; mas[i] != '\n'; i++)
                    {
                        printf("%c", mas[i]);
                    }

                    printf("\n");
                }
            } else
            {
                jpr(mas);
            }
        }
    }
}

//sablona pro zpracovani fonkci rows
void dopRows0(char* ar1, char* ar2, char* ar3, char* mas, int col_now, char delim)
{
    char* acolV = "acol";

    char* key = "-";
    int col_start, col_end;
    col_start = atoi(ar1);
    col_end = atoi(ar2);

    if (col_start <= col_now && col_end >= col_now)
    {
        if (strcmp(ar3, acolV) == 0)
        {
            acol( mas, delim);
        }
    } else
    {
        if (col_start <= col_now && ((strcmp(ar2, key) == 0)) && (strcmp(ar1, key) != 0))
        {
            if (strcmp(ar3, acolV) == 0)
            {
                acol( mas, delim);
            }
        } else
        {
            if ((strcmp(ar1, key) == 0) && (strcmp(ar2, key) == 0))
            {
                int i = 0;
                for (; mas[i] != EOF && mas[i] != '\n'; ++i)
                {

                }

                if (mas[i] == '\n')
                {
                    for (i = 0; mas[i] != EOF; i++)
                    {
                        printf("%c", mas[i]);

                        if (mas[i] == '\n')
                            break;
                    }
                }

                if (mas[i] == EOF)
                {

                }

                if (mas[i] == '\n')
                {
                    for (i = 0; mas[i] != '\n'; i++)
                    {
                        printf("%c", mas[i]);
                    }

                    printf("\n");
                }
            } else
            {
                jpr(mas);
            }
        }
    }
}

//spracuje pouze ukazane radky. pracuje s funkcemi o 2 uvedene argumenty
void rowsF2(char* ar1, char* ar2, char* ar3, char* ar4, char* ar5, char* mas, int si, char delim)
{
    char* csetV = "cset";
    char* copyV = "copy";
    char* swapV = "swap";
    char* moveV = "move";
    char* dcolsV = "dcols";

    if (strcmp(ar3, csetV) == 0)
    {
        dopRows2(ar1, ar2, ar3, ar4, ar5, mas, si, delim);
    }

    if (strcmp(ar3, swapV) == 0)
    {
        dopRows2(ar1, ar2, ar3, ar4, ar5, mas, si, delim);
    }

    if (strcmp(ar3, copyV) == 0)
    {
        dopRows2(ar1, ar2, ar3, ar4, ar5, mas, si, delim);
    }

    if (strcmp(ar3, moveV) == 0)
    {
        dopRows2(ar1, ar2, ar3, ar4, ar5, mas, si, delim);
    }

    if (strcmp(ar3, dcolsV) == 0)
    {
        dopRows2(ar1, ar2, ar3, ar4, ar5, mas, si, delim);
    }
}

//spracuje pouze ukazane radky. pracuje s funkcemi o 1 uvedeny argument
void rowsF1(char* ar1, char* ar2, char* ar3, char* ar4, char* mas, int si, char delim)
{
    char* icolV = "icol";
    char* dcolV = "dcol";

    char* tolowerV = "tolower";
    char* toupperV = "toupper";
    char* roundV = "round";
    char* intV = "int";


    if (strcmp(ar3, icolV) == 0)
    {
        dopRows1(ar1, ar2, ar3, ar4, mas, si, delim);
    }

    if (strcmp(ar3, dcolV) == 0)
    {
        dopRows1(ar1, ar2, ar3, ar4, mas, si, delim);
    }

    if (strcmp(ar3, tolowerV) == 0)
    {
        dopRows1(ar1, ar2, ar3, ar4, mas, si, delim);
    }

    if (strcmp(ar3, toupperV) == 0)
    {
        dopRows1(ar1, ar2, ar3, ar4, mas, si, delim);
    }

    if (strcmp(ar3, roundV) == 0)
    {
        dopRows1(ar1, ar2, ar3, ar4, mas, si, delim);
    }

    if (strcmp(ar3, intV) == 0)
    {
        dopRows1(ar1, ar2, ar3, ar4, mas, si, delim);
    }
}

//spracuje pouze ukazane radky
void rowsF0(char* ar1, char* ar2, char* ar3, char* mas, int si, char delim)
{
    char* acolV = "acol";

    if (strcmp(ar3, acolV) == 0)
    {
        dopRows0(ar1, ar2, ar3, mas, si, delim);
    }
}

//spracuje pouze radky racinaici ukazanym retezcem. pracuje s funkcemi o 2 uvedene argumenty
void beginsWith2(char* ar1, char* ar2, char* ar3, char* ar4, char* ar5, char* mas, char delim)
{
    char* csetV = "cset";
    char* copyV = "copy";
    char* swapV = "swap";
    char* moveV = "move";
    char* dcolsV = "dcols";

    char dopmas[100], col_we_need;
    int column = 1;
    int i = 0;
    int same = 0;
    col_we_need = atoi(ar1);

    for (int j=0; j < num_of_signs(ar2); ++j)
    {
        dopmas[j] = *(ar2 + j);
    }

    while (col_we_need > column)
    {
        while (mas[i] != EOF && mas[i] != '\n' && mas[i] != delim)
        {
            ++i;
        }
        if(mas[i] == '\n' || mas[i] == EOF)
            break;

        if(mas[i] == delim)
            ++column;
        ++i;
    }

    for (int j = 0; j < num_of_signs(ar2) ; ++j, ++i)
    {
        if (dopmas[j] == mas[i])
        {
            same = 0;
        } else
        {
            same = 1;
            break;
        }
    }

    if (strcmp(ar3, csetV) == 0)
    {
        if (same == 0)
        {
            cset(atoi(ar4),ar5, mas, delim);
        } else
        {
            jpr(mas);
        }
    }

    if (strcmp(ar3, copyV) == 0)
    {
        if (same == 0)
        {
            copyF(atoi(ar4),atoi(ar5), mas, delim);
        } else
        {
            jpr(mas);
        }
    }

    if (strcmp(ar3, swapV) == 0)
    {
        if (same == 0)
        {
            swapF(atoi(ar4),atoi(ar5), mas, delim);
        } else
        {
            jpr(mas);
        }
    }

    if (strcmp(ar3, moveV) == 0)
    {
        if (same == 0)
        {
            moveF(atoi(ar4),atoi(ar5), mas, delim);
        } else
        {
            jpr(mas);
        }
    }

    if (strcmp(ar3, dcolsV) == 0)
    {
        if (same == 0)
        {
            dcols(atoi(ar4),atoi(ar5), mas, delim);
        } else
        {
            jpr(mas);
        }
    }
}

//spracuje pouze radky zacinaici ukazanym retezcem. pracuje s funkcemi o 1 uvedene argumenty
void beginsWith1(char* ar1, char* ar2, char* ar3, char* ar4, char* mas, char delim)
{
    char* icolV = "icol";
    char* dcolV = "dcol";

    char* tolowerV = "tolower";
    char* toupperV = "toupper";
    char* roundV = "round";
    char* intV = "int";

    char dopmas[100], col_we_need;
    int column = 1;
    int i = 0;
    int same = 0;
    col_we_need = atoi(ar1);

    for (int k=0; k < num_of_signs(ar2); ++k)
    {
        dopmas[k] = *(ar2 + k);
    }

    while (col_we_need > column)
    {
        while (mas[i] != EOF && mas[i] != '\n' && mas[i] != delim)
        {
            ++i;
        }
        if(mas[i] == '\n' || mas[i] == EOF)
            break;

        if(mas[i] == delim)
            ++column;
        ++i;
    }

    for (int j = 0; j < num_of_signs(ar2) ; ++j, ++i)
    {
        if (dopmas[j] == mas[i])
        {
            same = 0;
        } else
        {
            same = 1;
            break;
        }
    }

    if (strcmp(ar3, icolV) == 0)
    {
        if (same == 0)
        {
            icol(atoi(ar4), mas, delim);
        } else
        {
            jpr(mas);
        }
    }

    if (strcmp(ar3, dcolV) == 0)
    {
        if (same == 0)
        {
            dcol(atoi(ar4), mas, delim);
        } else
        {
            jpr(mas);
        }
    }

    if (strcmp(ar3, tolowerV) == 0)
    {
        if (same == 0)
        {
            tlower(atoi(ar4), mas, delim);
        } else
        {
            jpr(mas);
        }
    }

    if (strcmp(ar3, toupperV) == 0)
    {
        if (same == 0)
        {
            tUpper(atoi(ar4), mas, delim);
        } else
        {
            jpr(mas);
        }
    }

    if (strcmp(ar3, roundV) == 0)
    {
        if (same == 0)
        {
            roundF(atoi(ar4), mas, delim);
        } else
        {
            jpr(mas);
        }
    }

    if (strcmp(ar3, intV) == 0)
    {
        if (same == 0)
        {
            intF(atoi(ar4), mas, delim);
        } else
        {
            jpr(mas);
        }
    }
}

//spracuje pouze radky zacinaici ukazanym retezcem
void beginsWith0(char* ar1, char* ar2, char* ar3, char* mas, char delim)
{
    char* acolV = "acol";

    char dopmas[100], col_we_need;
    int column = 1;
    int i = 0;
    int same = 0;
    col_we_need = atoi(ar1);

    for (int k=0; k < num_of_signs(ar2); ++k)
    {
        dopmas[k] = *(ar2 + k);
    }

    while (col_we_need > column)
    {
        while (mas[i] != EOF && mas[i] != '\n' && mas[i] != delim)
        {
            ++i;
        }
        if(mas[i] == '\n' || mas[i] == EOF)
            break;

        if(mas[i] == delim)
            ++column;
        ++i;
    }

    for (int j = 0; j < num_of_signs(ar2) ; ++j, ++i)
    {
        if (dopmas[j] == mas[i])
        {
            same = 0;
        } else
        {
            same = 1;
            break;
        }
    }

    if (strcmp(ar3, acolV) == 0)
    {
        if (same == 0)
        {
            acol( mas, delim);
        } else
        {
            jpr(mas);
        }
    }
}

//spracuje pouze radky obsahujici ukazany retezec. pracuje s funkcemi o 2 uvedene argumenty
void contains2(char* ar1, char* ar2, char* ar3, char* ar4, char* ar5, char* mas, char delim)
{
    char* csetV = "cset";
    char* copyV = "copy";
    char* swapV = "swap";
    char* moveV = "move";
    char* dcolsV = "dcols";

    char dopmas[100], col_we_need;
    int column = 1;
    int i = 0;
    int same = 0;
    col_we_need = atoi(ar1);

    for (int k=0; k < num_of_signs(ar2); ++k)
    {
        dopmas[k] = *(ar2 + k);
    }

    while (col_we_need > column)
    {
        while (mas[i] != EOF && mas[i] != '\n' && mas[i] != delim)
        {
            ++i;
        }
        if(mas[i] == '\n' || mas[i] == EOF)
            break;

        if(mas[i] == delim)
            ++column;
        ++i;
    }

    int j = 1;
    if (mas[i] == delim)
    {
        same = 1;
    }
    while (mas[i] != delim)
    {
        if (mas[i] == dopmas[0])
        {
            for (j = 0; j < num_of_signs(ar2) ; ++j, ++i)
            {
                if (dopmas[j] == mas[i])
                {
                    same = 0;
                } else
                {
                    same = 1;
                    break;
                }
            }
            if( j == num_of_signs(ar2))
                break;
        } else
        {
            same = 1;
        }
        ++i;
    }

    if (strcmp(ar3, csetV) == 0)
    {
        if (same == 0)
        {
            cset(atoi(ar4),ar5, mas, delim);
        } else
        {
            jpr(mas);
        }
    }

    if (strcmp(ar3, copyV) == 0)
    {
        if (same == 0)
        {
            copyF(atoi(ar4),atoi(ar5), mas, delim);
        } else
        {
            jpr(mas);
        }
    }

    if (strcmp(ar3, swapV) == 0)
    {
        if (same == 0)
        {
            swapF(atoi(ar4),atoi(ar5), mas, delim);
        } else
        {
            jpr(mas);
        }
    }

    if (strcmp(ar3, moveV) == 0)
    {
        if (same == 0)
        {
            moveF(atoi(ar4),atoi(ar5), mas, delim);
        } else
        {
            jpr(mas);
        }
    }

    if (strcmp(ar3, dcolsV) == 0)
    {
        if (same == 0)
        {
            dcols(atoi(ar4),atoi(ar5), mas, delim);
        } else
        {
            jpr(mas);
        }
    }
}

//spracuje pouze radky obsahujici ukazany retezec. pracuje s funkcemi o 1 uvedene argumenty
void contains1(char* ar1, char* ar2, char* ar3, char* ar4, char* mas, char delim)
{
    char* icolV = "icol";
    char* dcolV = "dcol";

    char* tolowerV = "tolower";
    char* toupperV = "toupper";
    char* roundV = "round";
    char* intV = "int";

    char dopmas[100], col_we_need;
    int column = 1;
    int i = 0;
    int same = 0;
    col_we_need = atoi(ar1);

    for (int j = 0; j < num_of_signs(ar2); ++j)
    {
        dopmas[j] = *(ar2 + j);
    }

    while (col_we_need > column)
    {
        while (mas[i] != EOF && mas[i] != '\n' && mas[i] != delim)
        {
            ++i;
        }
        if(mas[i] == '\n' || mas[i] == EOF)
            break;

        if(mas[i] == delim)
            ++column;
        ++i;
    }

    int j = 1;
    if (mas[i] == delim)
    {
        same = 1;
    }
    while (mas[i] != delim)
    {
        if (mas[i] == dopmas[0])
        {
            ++i;
            for (j = 1; j < num_of_signs(ar2) ; ++j, ++i)
            {
                if (dopmas[j] == mas[i])
                {
                    same =0;
                } else
                {
                    same = 1;
                    break;
                }
            }
            if( j == num_of_signs(ar2))
                break;
        } else
        {
            same = 1;
        }
        ++i;
    }

    if (strcmp(ar3, icolV) == 0)
    {
        if (same == 0)
        {
            icol(atoi(ar4), mas, delim);
        } else
        {
            jpr(mas);
        }
    }

    if (strcmp(ar3, dcolV) == 0)
    {
        if (same == 0)
        {
            dcol(atoi(ar4), mas, delim);
        } else
        {
            jpr(mas);
        }
    }

    if (strcmp(ar3, tolowerV) == 0)
    {
        if (same == 0)
        {
            tlower(atoi(ar4), mas, delim);
        } else
        {
            jpr(mas);
        }
    }

    if (strcmp(ar3, toupperV) == 0)
    {
        if (same == 0)
        {
            tUpper(atoi(ar4), mas, delim);
        } else
        {
            jpr(mas);
        }
    }

    if (strcmp(ar3, roundV) == 0)
    {
        if (same == 0)
        {
            roundF(atoi(ar4), mas, delim);
        } else
        {
            jpr(mas);
        }
    }

    if (strcmp(ar3, intV) == 0)
    {
        if (same == 0)
        {
            intF(atoi(ar4), mas, delim);
        } else
        {
            jpr(mas);
        }
    }
}

//spracuje pouze radky obsahujici ukazany retezec
void contains0(char* ar1, char* ar2, char* ar3, char* mas, char delim)
{
    char* acolV = "acol";

    char dopmas[100], col_we_need;
    int column = 1;
    int i = 0;
    int same = 0;
    col_we_need = atoi(ar1);

    for (int j = 0; j < num_of_signs(ar2); ++j)
    {
        dopmas[j] = *(ar2 + j);
    }

    while (col_we_need > column)
    {
        while (mas[i] != EOF && mas[i] != '\n' && mas[i] != delim)
        {
            ++i;
        }
        if(mas[i] == '\n' || mas[i] == EOF)
            break;

        if(mas[i] == delim)
            ++column;
        ++i;
    }

    int j = 1;
    if (mas[i] == delim)
    {
        same = 1;
    }
    while (mas[i] != delim)
    {
        if (mas[i] == dopmas[0])
        {
            ++i;
            for (; j < num_of_signs(ar2) ; ++j, ++i)
            {
                if (dopmas[j] == mas[i])
                {
                    same =0;
                } else
                {
                    same = 1;
                    break;
                }
            }
            if( j == num_of_signs(ar2))
                break;
        } else
        {
            same = 1;
        }
        ++i;
    }

    if (strcmp(ar3, acolV) == 0)
    {
        if (same == 0)
        {
            acol( mas, delim);
        } else
        {
            jpr(mas);
        }
    }
}


int main(int argc, char** argv)
{
     int i = 0;
     int end = 0;
     int last = 0;
     int size = 0;
     char delim;
     char ch, mas_ch[1000];

     char* key1   = "-d";
     char* irowV  = "irow";
     char* arowV = "arow";
     char* drowV = "drow";
     char* drowsV = "drows";
     char* icolV = "icol";
     char* acolV = "acol";
     char* dcolV = "dcol";
     char* dcolsV = "dcols";

     char* csetV = "cset";
     char* tolowerV = "tolower";
     char* toupperV = "toupper";
     char* roundV = "round";
     char* intV = "int";
     char* copyV = "copy";
     char* swapV = "swap";
     char* moveV = "move";

     char* rowsV = "rows";
     char* beginswithV = "beginswith";
     char* containsV = "contains";

    delim = delimetr(argv);

    if (argc > 1)
    {
        while (end == 0)
        {
            i = 0;

            memset(mas_ch, 0, 1000);

            while ((ch = getchar()) != EOF)
            {
                mas_ch[i] = ch;
                ++i;

                if (ch == '\n')
                    break;
            }
            ++size;

            if (ch == EOF)
            {
                mas_ch[i] = ch;
                last = 1;
                end = 1;
            }

            str_len(mas_ch, delim);

            if (i < 10240)
            {
                if (strcmp(argv[1], key1) == 0 && argc >= 3)
                {
                    if (strcmp(argv[3], irowV) == 0)
                    {
                        irow(atoi(argv[4]), mas_ch, size, delim);
                    }
                    else if (strcmp(argv[3], arowV) == 0)
                    {
                        arow(mas_ch, last);
                    }
                    else if (strcmp(argv[3], drowV) == 0)
                    {
                        drow(atoi(argv[4]), mas_ch, size);
                    }
                    else if (strcmp(argv[3], drowsV) == 0)
                    {
                        drows(atoi(argv[4]), atoi(argv[5]), mas_ch, size);
                    }
                    else if (strcmp(argv[3], icolV) == 0)
                    {
                        icol(atoi(argv[4]), mas_ch, delim);
                    }
                    else if (strcmp(argv[3], acolV) == 0)
                    {
                        acol(mas_ch, delim);
                    }
                    else if (strcmp(argv[3], dcolV) == 0)
                    {
                        dcol(atoi(argv[4]), mas_ch, delim);
                    }
                    else if (strcmp(argv[3], dcolsV) == 0)
                    {
                        dcols(atoi(argv[4]), atoi(argv[5]), mas_ch, delim);
                    }
                    else if (strcmp(argv[3], csetV) == 0)
                    {
                        cset(atoi(argv[4]), argv[5], mas_ch, delim);
                    }
                    else if (strcmp(argv[3], tolowerV)== 0)
                    {
                        tlower(atoi(argv[4]), mas_ch, delim);
                    }
                    else if (strcmp(argv[3], toupperV)== 0)
                    {
                        tUpper(atoi(argv[4]), mas_ch, delim);
                    }
                    else if (strcmp(argv[3], roundV)== 0)
                    {
                        roundF(atoi(argv[4]), mas_ch, delim);
                    }
                    else if (strcmp(argv[3], intV)== 0)
                    {
                        intF(atoi(argv[4]), mas_ch, delim);
                    }
                    else if (strcmp(argv[3], copyV)== 0)
                    {
                        copyF(atoi(argv[4]), atoi(argv[5]), mas_ch, delim);
                    }
                    else if (strcmp(argv[3], swapV)== 0)
                    {
                        swapF(atoi(argv[4]), atoi(argv[5]), mas_ch, delim);
                    }
                    else if (strcmp(argv[3], moveV)== 0)
                    {
                        moveF(atoi(argv[4]), atoi(argv[5]), mas_ch, delim);
                    }
                    else if (strcmp(argv[3], beginswithV)== 0)
                    {
                        if (argc == 9)
                        {
                            beginsWith2(argv[4], argv[5], argv[6], argv[7], argv[8], mas_ch, delim);
                        }

                        if (argc == 8)
                        {
                            beginsWith1(argv[4], argv[5], argv[6], argv[7], mas_ch, delim);
                        }

                        if (argc == 7)
                        {
                            beginsWith0(argv[4], argv[5], argv[6], mas_ch, delim);
                        }
                    }
                    else if (strcmp(argv[3], rowsV)== 0)
                    {
                        if (argc == 9)
                        {
                            rowsF2(argv[4], argv[5], argv[6], argv[7], argv[8], mas_ch, size, delim);
                        }

                        if (argc == 8)
                        {
                            rowsF1(argv[4], argv[5], argv[6], argv[7], mas_ch, size, delim);
                        }

                        if (argc == 7)
                        {
                            rowsF0(argv[4], argv[5], argv[6], mas_ch, size, delim);
                        }
                    }
                    else if (strcmp(argv[3], containsV)== 0)
                    {
                        if (argc == 9)
                        {
                            contains2(argv[4], argv[5], argv[6], argv[7], argv[8], mas_ch, delim);
                        }

                        if (argc == 8)
                        {
                            contains1(argv[4], argv[5], argv[6], argv[7], mas_ch, delim);
                        }

                        if (argc == 7)
                        {
                            contains0(argv[4], argv[5], argv[6], mas_ch, delim);
                        }
                    }
                } else
                    {
                        if (strcmp(argv[1], irowV) == 0)
                        {
                            irow(atoi(argv[2]), mas_ch, size, delim);
                        }
                        else if (strcmp(argv[1], arowV) == 0)
                        {
                            arow(mas_ch, last);
                        }

                        if (strcmp(argv[1], drowV) == 0)
                        {
                            drow(atoi(argv[2]), mas_ch, size);
                        }

                        if (strcmp(argv[1], drowsV) == 0)
                        {
                            drows(atoi(argv[2]), atoi(argv[3]), mas_ch, size);
                        }

                        if (strcmp(argv[1], icolV) == 0)
                        {
                            icol(atoi(argv[2]), mas_ch, delim);
                        }

                        if (strcmp(argv[1], acolV) == 0)
                        {
                            acol(mas_ch, delim);
                        }

                        if (strcmp(argv[1], dcolV) == 0)
                        {
                            dcol(atoi(argv[2]), mas_ch, delim);
                        }

                        if (strcmp(argv[1], dcolsV) == 0)
                        {
                            dcols(atoi(argv[2]), atoi(argv[3]), mas_ch, delim);
                        }

                        if (strcmp(argv[1], csetV) == 0)
                        {
                            cset(atoi(argv[2]), argv[3], mas_ch, delim);
                        }

                        if (strcmp(argv[1], tolowerV)== 0)
                        {
                            tlower(atoi(argv[2]), mas_ch, delim);
                        }

                        if (strcmp(argv[1], toupperV)== 0)
                        {
                            tUpper(atoi(argv[2]), mas_ch, delim);
                        }

                        if (strcmp(argv[1], roundV)== 0)
                        {
                            roundF(atoi(argv[2]), mas_ch, delim);
                        }

                        if (strcmp(argv[1], intV)== 0)
                        {
                            intF(atoi(argv[2]), mas_ch, delim);
                        }

                        if (strcmp(argv[1], copyV)== 0)
                        {
                            copyF(atoi(argv[2]), atoi(argv[3]), mas_ch, delim);
                        }

                        if (strcmp(argv[1], swapV)== 0)
                        {
                            swapF(atoi(argv[2]), atoi(argv[3]), mas_ch, delim);
                        }

                        if (strcmp(argv[1], moveV)== 0)
                        {
                            moveF(atoi(argv[2]), atoi(argv[3]), mas_ch, delim);
                        }


                        if (strcmp(argv[1], rowsV)== 0)
                        {
                            if (argc == 7)
                            {
                                rowsF2(argv[2], argv[3], argv[4], argv[5], argv[6], mas_ch, size, delim);
                            }

                            if (argc == 6)
                            {
                                rowsF1(argv[2], argv[3], argv[4], argv[5], mas_ch, size, delim);
                            }

                            if (argc == 5)
                            {
                                rowsF0(argv[2], argv[3], argv[4],  mas_ch, size, delim);
                            }
                        }

                        if (strcmp(argv[1], beginswithV)== 0)
                        {
                            if (argc == 7)
                            {
                                beginsWith2(argv[2], argv[3], argv[4], argv[5], argv[6], mas_ch, delim);
                            }

                            if (argc == 6)
                            {
                                beginsWith1(argv[2], argv[3], argv[4], argv[5], mas_ch, delim);
                            }

                            if (argc == 5)
                            {
                                beginsWith0(argv[2], argv[3], argv[4], mas_ch, delim);
                            }
                        }

                        if (strcmp(argv[1], containsV)== 0)
                        {
                            if (argc == 7)
                            {
                                contains2(argv[2], argv[3], argv[4], argv[5], argv[6], mas_ch, delim);
                            }

                            if (argc == 6)
                            {
                                contains1(argv[2], argv[3], argv[4], argv[5], mas_ch, delim);
                            }

                            if (argc == 6)
                            {
                                contains0(argv[2], argv[3], argv[4], mas_ch, delim);
                            }
                        }
                    }
            } else
                {
                    fprintf(stderr, "ERROR: the line is too long\n");//строка привышает нужно вывести ошибку
                    return 1;
                }
            }
    } else
        {
            fprintf(stderr, "ERROR\n");
            return 1;
        }
    memset(mas_ch, 0, 1000);
    return 0;
}
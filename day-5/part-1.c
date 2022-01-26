#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Point
{
    int x, y;
} Point;


int main()
{
    FILE *my_file = fopen("input.txt", "r");
    FILE *new_file = fopen("modified_input.txt", "w");

    //*****creating new formatted file************
    char temp;
    while((temp = getc(my_file)) != EOF)
    {
        if(temp == ',' || temp == '-' || temp == '>')
        {
            temp = ' ';
        }
        putc(temp, new_file);
    }
    fclose(new_file);
    fclose(my_file);
    new_file = fopen("modified_input.txt", "r");


    //*****creating map***********
    short **map = (short **)malloc(1000 * sizeof(short *));
    if(map == NULL)
    {
        printf("ERROR malloc");
        exit(-1);
    }
    for(int i = 0; i < 1000; ++i)
    {
        map[i] = (short *)calloc(1000, sizeof(short));
        if(map[i] == NULL)
        {
            printf("ERROR malloc");
            exit(-1);
        }
    }

    //*****filling the map*************
    char *x1 = (char *)malloc(3 * sizeof(char));
    char *y1 = (char *)malloc(3 * sizeof(char));
    char *x2 = (char *)malloc(3 * sizeof(char));
    char *y2 = (char *)malloc(3 * sizeof(char));
    Point p1, p2;
    int s, b; //smaller , bigger

    while(fscanf(new_file, "%s %s %s %s", x1, y1, x2, y2) == 4)
    {
        p1.x = atoi(x1);
        p1.y = atoi(y1);
        p2.x = atoi(x2);
        p2.y = atoi(y2);

        if(p1.x == p2.x)
        {
            s = (p2.y > p1.y)? p1.y : p2.y;
            b = (s == p1.y)? p2.y : p1.y;
            for(int i = s; i <= b; ++i)
            {
                (map[p1.x][i])++;
            }
        }else if(p1.y == p2.y)
        {
            s = (p2.x > p1.x)? p1.x : p2.x;
            b = (s == p1.x)? p2.x : p1.x;
            for(int i = s; i <= b; ++i)
            {
                (map[i][p1.y])++;
            }
        }
    }


    //*****counting points greater than or equal to 2********
    long n_points = 0;
    for(int i = 0; i < 1000; ++i)
    {
        for(int j = 0; j < 1000; ++j)
        {
            if(map[i][j] > 1)
            {
                n_points++;
            }
        }
    }

    printf("%ld", n_points);




    //*****freeing memory*********
    for(int i = 0; i < 1000; ++i)
    {
        free(map[i]);
    }
    free(map);
    free(x1);
    free(y1);
    free(x2);
    free(y2);

    fclose(new_file);
    return 0;
}













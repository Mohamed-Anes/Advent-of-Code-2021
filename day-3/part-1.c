#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define NB_BITS 12

int main()
{
    FILE *my_file = fopen("input.txt", "r");

    char *str = malloc(sizeof(int) * 12);
    int bits[NB_BITS] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int nb_lines = 0;
    int gamma_rate = 0, epsilon_rate = 0;

    while((fscanf(my_file, "%s", str)) == 1){
        for(int i = 0; i < NB_BITS; ++i)
        {
            if(str[i] == '1')
            {
                bits[i]++;
            }
        }
        nb_lines++;
    }

    printf("\n");

    for(int i = 0; i < NB_BITS; ++i)
    {
        printf("%d", bits[i]);
    }

    for(int i = 0; i < NB_BITS; ++i)
    {
        if((nb_lines - bits[i]) < nb_lines/2)
        {
            bits[i] = 1;
        }else
        {
            bits[i] = 0;
        }
    }

    printf("\n");
    for(int i = 0; i < NB_BITS; ++i)
    {
        printf("%d", bits[i]);
    }

    int p = 1;
    for(int i = NB_BITS - 1; i >= 0; --i)
    {
        gamma_rate += (p * bits[i]);
        bits[i] = !bits[i];
        epsilon_rate += (p * bits[i]);

        p *= 2;
    }

    printf("\n");
    for(int i = 0; i < NB_BITS; ++i)
    {
        printf("%d", bits[i]);
    }

    printf("\ngamma : %d \nepsilon : %d \nres : %ld", gamma_rate, epsilon_rate, gamma_rate * epsilon_rate);

    fclose(my_file);
    free(str);
    return 0;
    }



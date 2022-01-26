#include <stdio.h>
#include <stdlib.h>



#define DAYS 256

int main()
{
    FILE *my_file = fopen("input.txt", "r");

    long long int fish[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    long long int temp = 0;

    //*****filling initial state*******
    char temp_char;
    while((temp_char = getc(my_file)) != EOF)
    {
        if(temp_char != ',');
        fish[temp_char - '0']++;
    }

    //*****simulating growth over days******
    for(int i = 0; i < DAYS; ++i)
    {
        //printing values
        for(int j = 0; j < 9; ++j)
        {
            printf("%d : %lli  | ", j, fish[j]);
        }
        printf("\n");


        temp = fish[0];
        for(int j = 0; j < 8; ++j)
        {
            fish[j] = fish[j + 1];
        }
        fish[8] = temp;
        fish[6] += temp;
    }

    //*****calculating total******
    long long int total = 0;
    for(int i = 0; i < 9; ++i)
    {
        total += fish[i];
    }

    printf("%lli", total);




    fclose(my_file);
    return 0;
}













#include <stdio.h>
#include <stdlib.h>


int calculate_fuel(FILE *my_file, int p);

int main()
{
    FILE *my_file = fopen("input.txt", "r");
    FILE *new_file = fopen("modified_input.txt", "w");

    //*****creating new formatted file and counting numbers************
    char temp_char;
    while((temp_char = getc(my_file)) != EOF)
    {
        if(temp_char == ',')
        {
            temp_char = ' ';
        }
        putc(temp_char, new_file);
    }
    fclose(new_file);
    fclose(my_file);
    new_file = fopen("modified_input.txt", "r");

    //*****getting the sum of the numbers****
    int sum = 0;
    char *str = (char *)malloc(sizeof(char) * 6);
    int count = 0;

    while(fscanf(new_file, "%s", str) == 1)
    {
        sum += atoi(str);
        count++;
    }

    //*****calculating 'p' in Euclid's division a = p*q + r*****
    int p = sum/count;
    printf("sum : %d  count : %d\n", sum, count);

    //*****calculating the fuel used by all crabs*****
    int total = 1000000000;
    for(int i = 0; i < 1000; ++i)
    {
        sum = calculate_fuel(new_file, i);
        if(sum < total)
        {
            total = sum;
        }
        printf("sum : %lli  total : %d\n", sum, total);
    }

    printf("\np : %d  total : %d", p, total);  // 2497391096 too high

    fclose(my_file);
    return 0;
}



int calculate_fuel(FILE *new_file, int p)
{
    rewind(new_file);
    int number;
    int sum = 0;
    char *str = (char *)malloc(sizeof(char) * 6);
    while(fscanf(new_file, "%s", str) == 1)
    {
        number = atoi(str);
        sum += (number > p)? (number - p)*(number - p + 1)/2 : (p - number)*(p - number + 1)/2;
    }
    return sum;
}








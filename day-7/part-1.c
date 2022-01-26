#include <stdio.h>
#include <stdlib.h>


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
    long int sum = 0;
    char *str = (char *)malloc(sizeof(char) * 6);
    int count = 0;

    while(fscanf(new_file, "%s", str) == 1)
    {
        sum += atoi(str);
        count++;
    }

    //*****calculating 'p' in Euclid's division a = p*q + r*****
    int p = sum/count;
    printf("sum : %li  count : %d\n", sum, count);

    //*****calculating the fuel used by all crabs*****
    long int total = 1000000;
    for(int i = p; i >= 0; --i)
    {
        rewind(new_file);
        int number;
        sum = 0;
        while(fscanf(new_file, "%s", str) == 1)
        {
            number = atoi(str);
            sum += (number > i)? (number - i) : (i - number);
        }
        if(sum < total)
        {
            total = sum;
        }
    }

    printf("\np : %d  total : %d", p, total);

    fclose(my_file);
    return 0;
}













#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getln(FILE *my_file, char *str);

int main()
{
    FILE *my_file = fopen("input.txt", "r");

    char *str = malloc(sizeof(char) * 10);
    int depth = 0, distance = 0;
    int aim = 0;
    int temp;


    while((fscanf(my_file, "%s %d", str, &temp)) == 2){
        switch(str[0]){
        case 'u':
            aim -= temp;
            break;
        case 'd':
            aim += temp;
            break;
        case 'f':
            distance += temp;
            depth += aim * temp;
            break;
            }
        }

    printf("%d\n", depth * distance);

    fclose(my_file);
    free(str);
    return 0;
    }

/*
int getln(FILE *my_file, char *str){
    char temp;
    int i = 0;
    while((temp = getc(my_file)) != '\n'){
        if(temp == EOF){
            return -1;
            }
        str[i++] = temp;
        }
    return 0;
    }
*/

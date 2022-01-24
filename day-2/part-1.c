#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getlin(FILE *my_file, char *str);

int main()
{
    FILE *my_file = fopen("input.txt", "r");

    char *str_depth = malloc(sizeof(char) * 10);
    int depth = 0, distance = 0;



    while((getlin(my_file, str_depth)) == 0){
        switch(str_depth[0]){
        case 'u':
            depth -= atoi(str_depth + 3);
            break;
        case 'd':
            depth += atoi(str_depth + 5);
            break;
        case 'f':
            distance += atoi(str_depth + 8);
            break;
            }
        }

    printf("%d\n", depth * distance);

    fclose(my_file);
    free(str_depth);
    return 0;
    }


int getlin(FILE *my_file, char *str){
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    FILE *my_file = fopen("input.txt", "r");

    char *str_depth = malloc(sizeof(char) * 5);
    int depth_1 = 1000000, depth_2, depth_3, depth_4, counter = 0;
    char temp;



    while((getline(my_file, str_depth)) == 0){
        depth_2 = depth_1;
        depth_1 = atoi(str_depth);

        if(depth_1 > depth_2){
            ++counter;
        }

        printf("%d\n", depth_1);
        }

    printf("%d\n", counter);

    fclose(my_file);
    return 0;
    }


int getline(FILE *my_file, char *str){
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

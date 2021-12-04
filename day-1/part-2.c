#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getline(FILE *my_file, char *str);

int main()
{
    FILE *my_file = fopen("input.txt", "r");

    char *str_depth = malloc(sizeof(char) * 5);
    int depth[4], counter = 0, sum_1, sum_2;

    for(int i = 0; i < 4; ++i){
        getline(my_file, str_depth);
        depth[i] = atoi(str_depth);
        }
    sum_1 = depth[0] + depth[1] + depth[2];
    sum_2 = depth[1] + depth[2] + depth[3];

    if(sum_1 < sum_2){
            ++counter;
        }


    while((getline(my_file, str_depth)) == 0){

        sum_1 -= depth[0];
        sum_2 -= depth[1];

        for(int i = 0; i < 3; ++i){
            depth[i] = depth[i + 1];
        }
        depth[3] = atoi(str_depth);

        sum_1 += depth[2];
        sum_2 += depth[3];

        if(sum_1 < sum_2){
            ++counter;
        }

        }

    printf("%d\n", counter);

    fclose(my_file);
    free(str_depth);
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

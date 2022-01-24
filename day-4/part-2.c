#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Number
{
    int value;
    int is_marked;
} Number;

typedef struct Grid
{
    Number *numbers;
} Grid;


int get_nb_boards(FILE *my_file);
void mark_numbers(Grid *grids, int number, int nb_boards);
int check_win(Grid *grids, int nb_boards, Grid *last);
int check_board_win(Grid grid);


int main()
{
    FILE *my_file = fopen("input.txt", "r");
    char *draws = malloc(sizeof(char) * 1000);
    char *str = malloc(sizeof(char) * 20);

    int nb_boards = get_nb_boards(my_file); //getting number of boards

    fscanf(my_file, "%s", draws);

    Grid *grids = (Grid *)malloc(sizeof(Grid) * nb_boards); //allocating table of grids

    for(int i = 0; i < nb_boards; ++i) //allocating and filling grids
    {
        grids[i].numbers = (Number *)malloc(sizeof(Number) * 25);

        for(int j = 0; j < 25; ++j)
        {
            fscanf(my_file, "%s", str);
            grids[i].numbers[j].value = atoi(str);
            grids[i].numbers[j].is_marked = 0;
            //printf("%d ", grids[i].numbers[j].value);
        }
        //printf("\n\n");
    }

    int last_win_number;
    Grid last_win_grid;
    last_win_grid.numbers = (Number *)malloc(sizeof(Number) * 25);
    char *str_number = strtok(draws, ",");
    int number = atoi(str_number);
    int winning_board;
    while(str_number != NULL)
    {
        //printf("\n%s %d", str_number, number);
        mark_numbers(grids, number, nb_boards);

        if((winning_board = check_win(grids, nb_boards, &last_win_grid)) != -1)
        {

            last_win_number = number;

        }
        str_number = strtok(NULL, ",");
        number = atoi(str_number);
    }

    printf("last win number : %d  winning board : %d\n\n", last_win_number, winning_board);


    for(int n = 0; n < nb_boards; ++n)
    {
        printf(" %d \n", n);
        if(grids[n].numbers){
            for(int i = 0; i < 5; ++i)
            {
                for(int j = 0; j < 5; ++j)
                {
                    printf("%d ", grids[n].numbers[5*i + j].is_marked);
                }
                printf("\n");
            }
            printf("\n");
        }
    }


    printf("..\n");
    for(int i = 0; i < 5; ++i)
    {
        for(int j = 0; j < 5; ++j)
        {
            printf("%d ", last_win_grid.numbers[5*i + j].is_marked);
        }
        printf("\n");
    }
    printf("\n");


    int score = 0;
    for(int i = 0; i < 25; ++i) //calculating score
    {
        if(!last_win_grid.numbers[i].is_marked)
        {
            score += last_win_grid.numbers[i].value;
        }
    }
    score *= last_win_number;

    printf("\n\nscore : %d", score);

    fclose(my_file);
    return 0;
}


int get_nb_boards(FILE *my_file)
{
    rewind(my_file);

    char temp, previous = 'a';
    int nb_boards = 0;

    while((temp = getc(my_file)) != EOF)
    {
        if(temp == previous && temp == '\n')
        {
            nb_boards++;
        }

        previous = temp;

    }

    rewind(my_file);
    return nb_boards;

}

void mark_numbers(Grid *grids, int number, int nb_boards)
{
    for(int i = 0; i < nb_boards; ++i)
    {
        if(grids[i].numbers){
            for(int j = 0; j < 25; ++j)
            {
                if(grids[i].numbers[j].value == number)
                {
                    grids[i].numbers[j].is_marked = 1;
                }
            }
        }
    }
}

int check_win(Grid *grids, int nb_boards, Grid *last)
{
    int returned = -1;
    for(int i = 0; i < nb_boards; ++i)
    {
        if(grids[i].numbers != NULL)
        {
            if(check_board_win(grids[i]))
            {
                //grids[i].numbers = NULL;
                for(int j = 0; j < 25; ++j) //copy the last winning grid
                {
                    last->numbers[j].value = grids[i].numbers[j].value;
                    last->numbers[j].is_marked = grids[i].numbers[j].is_marked;
                }
                grids[i].numbers = NULL;
                //return i;
                returned = i;
                printf("\n--%d--\n", i);
            }
        }
    }
    return returned;
}

int check_board_win(Grid grid)
{
    int win_v, win_h;
    for(int i = 0; i < 5; ++i)
    {
        win_v = 1;
        win_h = 1;
        for(int j = 0; j < 5; ++j)
        {
            if(grid.numbers[5*j + i].is_marked == 0)
            {
                win_v = 0;
            }
            if(grid.numbers[5*i + j].is_marked == 0)
            {
                win_h = 0;
            }
        }
        if(win_v || win_h)
        {
            return 1;
        }
    }
    return 0;
}





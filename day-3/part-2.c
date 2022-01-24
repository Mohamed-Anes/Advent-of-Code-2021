#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//full of bugs but works with given input

#define NB_BITS 12

int main()
{
    FILE *my_file = fopen("input.txt", "r");

    char *str = malloc(sizeof(int) * 12);
    int gen_bits[NB_BITS] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int scrub_bits[NB_BITS] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int nb_elements_gen = 0;
    int nb_elements_scrub = 0;
    int generator_rate = 0, scrubber_rate = 0;
    int bool_gen = 1;
    int bool_scrub = 1;
    int bool_gen_2 = 1;
    int bool_scrub_2 = 1;
    int temp_gen, temp_scrub;

    //********calculating rates
    for(int i = 0; i < NB_BITS; ++i)
    {
        rewind(my_file);
        nb_elements_gen = 0;
        nb_elements_scrub = 0;
        while((fscanf(my_file, "%s", str)) == 1){
            bool_gen = 1;
            bool_scrub = 1;
            for(int j = 0; j < i; ++j) //checking if element should be tested
            {
                if((str[j] - '0') != gen_bits[j])
                {
                    bool_gen = 0;
                }
                if((str[j] - '0') != scrub_bits[j])
                {
                    bool_scrub = 0;
                }
            }

            if(bool_gen){ //counting occurences of 1 and total elements
                if(str[i] == '1')
                {
                    gen_bits[i]++;
                }else
                {
                    gen_bits[i]--;
                }
                nb_elements_gen++;
                //if(str[i + 1]  temp_gen){
                    temp_gen = str[i + 1];
                //}
            }
            if(bool_scrub){ //counting occurences of 1 and total elements
                if(str[i] == '1')
                {
                    scrub_bits[i]++;
                }else
                {
                    scrub_bits[i]--;
                }
                nb_elements_scrub++;
                temp_scrub = str[i + 1];
            }
        }


        if(nb_elements_gen > 1 && bool_gen_2){
            if(gen_bits[i] >= 0) //determining 0 or 1
            {
                gen_bits[i] = 1;
            }else if(bool_gen_2)
            {
                gen_bits[i] = 0;
            }
        }

        if(nb_elements_scrub > 1 && bool_scrub_2){
            if(scrub_bits[i] < 0) //determining 0 or 1
            {
                scrub_bits[i] = 1;
            }else if(bool_scrub_2)
            {
                scrub_bits[i] = 0;
            }
        }

        if(nb_elements_gen == 1) //case if no elements remain
        {
            rewind(my_file);
            while((fscanf(my_file, "%s", str)) == 1){
                bool_gen = 1;
                for(int j = 0; j < i; ++j) //checking if element should be tested //4480428  4474944  4474944
                {
                    if((str[j] - '0') != gen_bits[j])
                    {
                        bool_gen = 0;
                    }
                }
                if(bool_gen)
                {
                    for(int j = 0; j < NB_BITS; ++j)
                    {
                        gen_bits[j] = str[j] - '0';
                    }
                }
                bool_gen_2 = 0;
            }

        }
        if(nb_elements_scrub == 1) //case if no elements remain
        {
            rewind(my_file);
            while((fscanf(my_file, "%s", str)) == 1){
                bool_scrub = 1;
                for(int j = 0; j < i; ++j) //checking if element should be tested
                {
                    if((str[j] - '0') != scrub_bits[j])
                    {
                        bool_scrub = 0;
                    }
                }
                if(bool_scrub)
                {
                    for(int j = 0; j < NB_BITS; ++j)
                    {
                        scrub_bits[j] = str[j] - '0';
                    }
                }
                bool_scrub_2 = 0;
            }
        }


        printf("\n%d : nb gen : %d nb scrub : %d", i, nb_elements_gen, nb_elements_scrub);
    }


    int p = 1; //converting gamma rate to decimal
    for(int i = NB_BITS - 1; i >= 0; --i)
    {
        generator_rate += (p * gen_bits[i]);
        scrubber_rate += (p * scrub_bits[i]);

        p *= 2;
    }

    printf("\n");
    for(int i = 0; i < NB_BITS; ++i)
    {
        printf("%d", gen_bits[i]);
    }

    printf("\n");
    for(int i = 0; i < NB_BITS; ++i)
    {
        printf("%d", scrub_bits[i]);
    }

    printf("\ngenerator : %d \nscrubber : %d \nres : %ld", generator_rate, scrubber_rate, generator_rate * scrubber_rate);

    fclose(my_file);
    free(str);
    return 0;
    }



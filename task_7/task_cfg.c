#include <stdio.h>
#include <stdlib.h>

#define get_arg(name, argv_index)                                                              \
    do                                                                                         \
    {                                                                                          \
        int __num_read = sscanf(argv[(argv_index)], "%u", &(name));                            \
        if (1 != __num_read)                                                                   \
        {                                                                                      \
            printf("Bad arg \"%s\": should be unsigned, got %s\n", #name, argv[(argv_index)]); \
            return -1;                                                                         \
        }                                                                                      \
        if ((name) < 1)                                                                        \
        {                                                                                      \
            printf("Bad arg \"%s\": should be >= 1, got %u\n", #name, (unsigned)(name));       \
            return -1;                                                                         \
        }                                                                                      \
    } while (0)

int main(int argc, char *argv[])
{
    ///

    unsigned mul = 0;
    unsigned add = 0;
    unsigned mod = 0;
    unsigned p = 0;
    unsigned xor = 0;

    unsigned i = 0;
    unsigned j = 0;

    unsigned *arr = NULL;

    if (argc < 5)
    {
        goto error_1;
    }
    else
    {
        goto continue_1;
    }

error_1:
    printf("Not enough args!\n");
    return -1;

continue_1:
    get_arg(mul, 1);
    get_arg(add, 2);
    get_arg(mod, 3);
    get_arg(p, 4);

    arr = calloc(mod * p, sizeof(unsigned));
    i = 0;
    goto main_loop;

main_loop:
    if (0 == mod % 2)
    {
        goto step_1_true;
    }
    else
    {
        goto step_1_false;
    }

step_1_true:
    arr[i * p + 0] = (i * mul + add) % mod;
    goto main_loop_1;

step_1_false:
    arr[i * p + 0] = (i * add + mul) % mod;
    goto main_loop_1;

main_loop_1:
    xor ^= arr[i * p + 0];
    j = 1;
    goto inner_loop;

inner_loop:
    if (0 == mod % 2)
    {
        goto inner_step_true;
    }
    else
    {
        goto inner_step_false;
    }

inner_step_true:
    arr[i * p + j] = (arr[i * p + (j - 1)] * mul + add) % mod;
    goto inner_loop_1;

inner_step_false:
    arr[i * p + j] = (arr[i * p + (j - 1)] * add + mul) % mod;
    goto inner_loop_1;

inner_loop_1:
    xor ^= arr[i * p + j];
    j++;
    if (j < p)
    {
        goto inner_loop;
    }
    else
    {
        goto step_2;
    }

step_2:
    i++;
    if (i < mod)
    {
        goto main_loop;
    }
    else
    {
        goto finish_loop_setup;
    }

finish_loop_setup:
    i = 0;

finish_loop:
    printf("%d\n", arr[i * p + i]);
    i++;
    if (i < mod && i < p && i < 10)
    {
        goto finish_loop;
    }
    else
    {
        goto finish;
    }

finish:
    free(arr);
    return 0;

    ////
}

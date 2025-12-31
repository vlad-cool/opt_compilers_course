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
        printf("Not enough args!\n");
        return -1;
    }

    get_arg(mul, 1);
    get_arg(add, 2);
    get_arg(mod, 3);
    get_arg(p, 4);

    arr = calloc(mod * p, sizeof(unsigned));

    for (i = 0; i < mod; i++)
    {
        if (0 == mod % 2)
        {
            arr[i * p + 0] = (i * mul + add) % mod;
        }
        else
        {
            arr[i * p + 0] = (i * add + mul) % mod;
        }
        xor ^= arr[i * p + 0];

        for (j = 1; j < p; j++)
        {
            if (0 == mod % 2)
            {
                arr[i * p + j] = (arr[i * p + (j - 1)] * mul + add) % mod;
            }
            else
            {
                arr[i * p + j] = (arr[i * p + (j - 1)] * add + mul) % mod;
            }
            xor ^= arr[i * p + j];
        }
    }

    for (i = 0; i < mod && i < p && i < 10; i++)
    {
        printf("%d\n", arr[i * p + i]);
    }

    free(arr);
    return 0;
}

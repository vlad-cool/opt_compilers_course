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

    unsigned i = 0;
    unsigned j = 0;

    unsigned ip;
    unsigned ipj;

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

    if (0 == mod % 2)
    {
        for (i = 0; i < mod; i++)
        {
            ip = i * p;
            
            arr[ip] = (i * mul + add) % mod;
            
            for (j = 1; j < p; j++)
            {
                ipj = ip + j;
                arr[ipj] = (arr[ipj - 1] * mul + add) % mod;
            }
        }
    }
    else
    {
        for (i = 0; i < mod; i++)
        {
            ip = i * p;
            
            arr[ip] = (i * add + mul) % mod;
            
            for (j = 1; j < p; j++)
            {
                ipj = ip + j;
                arr[ipj] = (arr[ipj - 1] * add + mul) % mod;
            }
        }
    }

    for (i = 0; i < mod && i < p && i < 10; i++)
    {
        printf("%d\n", arr[i * p + i]);
    }

    free(arr);
    return 0;
}

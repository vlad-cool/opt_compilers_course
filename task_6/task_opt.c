#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("No args given! Should be 2 integer args.\n");
        return -1;
    }
    int length = 0;
    int num_read = sscanf(argv[1], "%d", &length);
    if (1 != num_read)
    {
        printf("Given arg \"%s\" should be a number!\n", argv[1]);
        return -1;
    }

    int num_loops = 0;
    num_read = sscanf(argv[2], "%d", &num_loops);
    if (1 != num_read)
    {
        printf("Given arg \"%s\" should be a number!\n", argv[2]);
        return -1;
    }

    int last_sum = 0;
    for (int j = 0; j < num_loops; j++)
    {
        int sum = 0;
        for (int i = 0; i < length; i++)
        {
            // int ip2 = (int)pow((double)i, 2.0);
            int ip2 = i * i;
            // Overflow incorrect behaviour? It is UB anyway
            sum += (ip2 >> 2) + (ip2 >> 4);
        }
        last_sum = sum;
    }

    printf("%d\n", last_sum);
    return 0;
}

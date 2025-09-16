// Variant 3
#include <stdio.h>

int main()
{
    int arg = 0;
    scanf("%d", &arg);
    int res = 0;
    for (int i = 0; i < arg; i++)
    {
        int j = 1;
        do
        {
            res += i % j;
            j++;
        } while (j < i);
    }
    printf("%d\n", res);
    return 0;
}

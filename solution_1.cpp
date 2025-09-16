// Variant 3
#include <stdio.h>

int main()
{
    int arg = 0;
    int res = 0;

    int i = 0;
    int j = 0;

    int tmp = 0;

    bool main_loop_cond = false;
    bool main_loop_break_cond = false;
    bool inner_loop_cond = false;

    scanf("%d", &arg);

main_loop:
    main_loop_cond = i < arg;
    main_loop_break_cond = !main_loop_cond;

    if (main_loop_break_cond)
    {
        goto main_loop_end;
    }
    else
    {
        goto main_loop_body;
    }

main_loop_body:

    j = 1;

inner_loop:
    tmp = i % j;
    res = res + tmp;
    j = j + 1;

    inner_loop_cond = j < i;

    if (inner_loop_cond)
    {
        goto inner_loop;
    }
    else
    {
        goto inner_loop_end;
    }

inner_loop_end:

    i = i + 1;
    goto main_loop;
main_loop_end:

    printf("%d\n", res);
    return 0;
}

#include <stdlib.h>
#include <stdio.h>

void a_times_b_tr(int n, double **a, double **b, double **c)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < n; k++)
            {
                c[i][j] += a[i][k] * b[j][k];
            }
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s n m\n", argv[0]);
        return -1;
    }

    FILE *file_a = fopen("a.txt", "r");
    if (file_a == NULL)
    {
        printf("Error opening file a.txt");
        return 1;
    }
    FILE *file_b = fopen("b.txt", "r");
    if (file_b == NULL)
    {
        fclose(file_a);
        printf("Error opening file b.txt");
        return 1;
    }

    int n = atoi(argv[1]);
    int m = atoi(argv[2]);

    double **a = malloc(sizeof(double *) * n);
    a[0] = malloc(sizeof(double) * n * n);
    double **b = malloc(sizeof(double *) * n);
    b[0] = malloc(sizeof(double) * n * n);
    double **c = malloc(sizeof(double *) * n);
    c[0] = malloc(sizeof(double) * n * n);

    for (int i = 1; i < n; i++)
    {
        a[i] = a[i - 1] + n;
        b[i] = b[i - 1] + n;
        c[i] = c[i - 1] + n;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fscanf(file_a, "%lf", &a[i][j]);
            fscanf(file_b, "%lf", &b[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            double tmp = b[i][j];
            b[i][j] = b[j][i];
            b[j][i] = tmp;
        }
    }

    fclose(file_a);
    fclose(file_b);

    for (int i = 0; i < m; i++)
    {
        a_times_b_tr(n, a, b, c);
        double **tmp = c;
        c = a;
        a = tmp;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%lf ", a[i][j]);
        }
        printf("\n");
    }

    free(a[0]);
    free(a);
    free(b[0]);
    free(b);
    free(c[0]);
    free(c);
}

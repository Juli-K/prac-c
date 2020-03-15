#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int n;

int main(void)
{
    scanf("%d", &n);
    double *x, **a;
    x = calloc(n, sizeof(double));
    a = calloc(n, sizeof(double));
    for (int i = 0; i < n; i++)
    {
        a[i] = calloc(n + 1, sizeof(double*));
        for (int j = 0; j < n + 1; j++)
            scanf("%lf", &a[i][j]);
    }
    int i_max = 0;
    double max;
    for (int i = 0; i < n; i++)
    {
        max = abs(a[i][i]);
        i_max = i;
        for (int j = i + 1; j < n; j++)
        {
            int flag = 0;
            if (a[j][i] > max)
            {
                i_max = j;
                max = a[j][i];
                flag = 1;
            }
            if (flag)
            {
                for (int k = 0; k <= n; k++)
                {
                    double tmp = a[i][k];
                    a[i][k] = a[i_max][k];
                    a[i_max][k] = tmp;
                }
            }
        }
        for (int k = i; k < n; k++)
        {
            double tmp = a[k][i];
            if ((long int)(tmp*1000000000000) == 0)
                continue;
            for (int j = 0; j < n + 1; j++)
                a[k][j] = a[k][j] / tmp;
            if (k == i)
                continue;
            for (int j = 0; j < n + 1; j++)
                a[k][j] -= a[i][j];
        }
    }
    for (int k = n - 1; k >= 0; k--)
    {
        x[k] = a[k][n];
        for (int i = 0; i < k; i++)
            a[i][n] -= a[i][k] * x[k];
    }
    for (int i = 0; i < n; i++)
        printf("%0.f\n", round(x[i]));
    for (int i = n - 1; i >= 0; i--)
        free(a[i]);
    free(a);
    free(x);
    return 0;
}


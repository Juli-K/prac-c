#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
    scanf ("%d", &n);
    long int **p;
    p = calloc(n, sizeof(long int*));
    for (int i = 0; i < n; i++)
        p[i] = calloc(2 * n, sizeof(long int));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 2 * n; j++)
            scanf("%ld", &p[i][j]);
    for (int i = 0; i < n; i++)
      {

        for (int j = 2 * i; j < (2 * n); j += 2)
        {
            if (2 * i == j)
            {
                p[i][j + 1] = -p[i][j + 1];

            }
            else if (2 * i != j)
            {

                long int tmp = p[i][j];
                p[i][j] = p[j / 2][2 * i];
                p[j / 2][2 * i] = tmp;
                tmp = p[i][j + 1];
                p[i][j + 1] = -p[j / 2][i * 2 + 1];
                p[j / 2][i * 2 + 1] = -tmp;

            }
        }
      }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2 * n; j++)
            printf ("%ld ", p[i][j]);
        printf ("\n");
    }
    for (int i = n - 1; i >= 0; i--)
        free(p[i]);
    free(p);
    return 0;
}

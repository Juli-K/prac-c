#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, check = 0;
    scanf ("%d", &n);
    int a[n + 1];
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n - 2; i++)
    {
        for (int j = i + 2; j <= n; j++)
        {
            int k = (i + j) / 2;
            if (a[k] * 2 == a[i] + a[j] && (i + j) % 2 == 0 && (a[i] + a[j]) % 2 == 0)
                check++;
        }
    }
    printf ("%d", check);
    return 0;
}

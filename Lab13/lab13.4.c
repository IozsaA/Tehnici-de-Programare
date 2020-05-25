#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void permute(char *a, int l, int r)
{
    int i, k, ok = 0;
    int n = strlen(a);
    if (l == r)
    {
        for (k = 0; k < n; k++)
        {
            if ((a[k] == 'a' && a[k + 1] == 'b') ||
                (a[k] == 'a' && a[k - 1] == 'b') ||
                (a[k] == 'a' && a[k + 1] == 'c') ||
                (a[k] == 'a' && a[k - 1] == 'c') ||
                (a[k] == 'b' && a[k + 1] == 'g') ||
                (a[k] == 'b' && a[k - 1] == 'g'))
                ok = 1;
        }
        if (ok == 0)
            printf("%s\n", a);
    }
    else
    {
        for (i = l; i <= r; i++)
        {
            swap((a + l), (a + i));
            permute(a, l + 1, r);
            swap((a + l), (a + i));
        }
    }
}

int main()
{

    int a, b, c, g, i = 0;

    printf("Ateliere:");
    scanf("%d", &a);
    printf("Blocuri:");
    scanf("%d", &b);
    printf("Case:");
    scanf("%d", &c);
    printf("Gradini:");
    scanf("%d", &g);

    int n = a + b + c + g;

    char v[n];

    for (i = 0; i < a; i++)
        v[i] = 'a';
    for (i = a; i < b + a; i++)
        v[i] = 'b';
    for (i = b + a; i < c + b + a; i++)
        v[i] = 'c';
    for (i = c + b + a; i < n; i++)
        v[i] = 'g';
    v[i] = '\0';

    permute(v, 0, n - 1);

    return 0;
}

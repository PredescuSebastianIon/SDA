#include <stdio.h>
#define NMAX 1000

int main()
{
    int n;
    scanf("%d", &n);
    int a[NMAX];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    // sortam prin selectie acum
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] > a[j]) {
                int aux = a[i];
                a[i] = a[j];
                a[j] = aux;
            }

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}

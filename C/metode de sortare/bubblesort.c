#include <stdio.h>
#define NMAX 1000

int main()
{
    int n;
    scanf("%d", &n);
    int a[NMAX];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    // sortam prin bubblesort acum
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1]) {
                int aux = a[j];
                a[j] = a[j + 1];
                a[j + 1] = aux;
            }

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}

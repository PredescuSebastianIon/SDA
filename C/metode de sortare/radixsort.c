#include <stdio.h>
#define NMAX 1000

void radixsort(int a[], int n, int power)
{
    int frecv[10][NMAX] = {0}, cnt[10] = {0};
    for (int i = 0; i < n; i++) {
        int digit = (a[i] / power) % 10;
        frecv[digit][cnt[digit]++] = a[i];
    }

    int Max = 0, poz = 0;
    for (int digit = 0; digit < 10; digit++) {
        for (int i = 0; i < cnt[digit]; i++) {
            a[poz++] = frecv[digit][i];
            if (a[poz - 1] > Max)
                Max = a[poz - 1];
        }
    }

    if (Max > power * 10 && power < 1e18)
        radixsort(a, n, power * 10);
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[NMAX];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    // sortam prin radix sort acum
    radixsort(a, n, 1);

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}

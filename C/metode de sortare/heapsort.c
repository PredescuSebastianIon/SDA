#include <stdio.h>
#define NMAX 1000

void swap(int *x, int *y)
{
    int aux = *x;
    *x = *y;
    *y = aux;
    return;
}

void heap_up(int a[], int poz)
{
    while (poz > 1) {
        int tata = poz / 2;
        if (a[poz] > a[tata]) {
            int aux = a[poz];
            a[poz] = a[tata];
            a[tata] = aux;
            poz = tata;
        }
        else
            break;
    }
}

int heap_down(int a[], int *n) {
    int Max = a[1];
    swap(&a[1], &a[*n]);
    a[*n] = 0;
    *n = *n - 1;
    int poz = 1;
    while (2 * poz <= *n) {
        int pozmax = 0;
        if (poz * 2 <= *n && poz * 2 + 1 <= *n) {
            pozmax = poz * 2;
            if (a[poz * 2] < a[poz * 2 + 1])
                pozmax++;
        }
        else if (poz * 2 <= *n)
            pozmax = poz * 2;
        else
            break;

        if (a[poz] < a[pozmax]) {
            swap(&a[poz], &a[pozmax]);
            poz = pozmax;
        }
        else
            break;
    }
    return Max;
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[NMAX];
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        heap_up(a, i);
    }

    // extragem valorile din heap
    int N = n;
    for (int i = 1; i <= N; i++)
        printf("%d ", heap_down(a, &n));
    printf("\n");
    return 0;
}

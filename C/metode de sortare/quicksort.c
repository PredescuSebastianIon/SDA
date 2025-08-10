#include <stdio.h>
#define NMAX 1000

void quicksort(int a[], int left, int right)
{
    // Cazul banal sau cazul imposibil
    if (left >= right)
        return;
    
    // Alegem pivotul
    // in mod normal, pentru cele mai bune rezultate se alege random pivotul
    // Pentru simplitate, noi il vom alege ca fiind a[left]
    // Pentru simplitate vom folosi de asemenea un vector auxiliar

    int pivot = a[left];
    int poz = left + 1;
    int contor_left = left, contor_right = right, aux[NMAX] = {0};
    while (poz <= right) {
        if (a[poz] > pivot)
            aux[contor_right--] = a[poz++];
        else
            aux[contor_left++] = a[poz++];
    }
    // mai ramane de asezat pivotul (la final contor_left == contor_right)
    aux[contor_left] = pivot;

    // varsam vectorul auxiliar in cel initial
    for (int i = left; i <= right; i++)
        a[i] = aux[i];

    // sortam intervalele mai mici
    // fara pozitia pivotului
    quicksort(a, left, contor_left - 1);
    quicksort(a, contor_left + 1, right);
    return;
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[NMAX];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    // apelam functia
    quicksort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}

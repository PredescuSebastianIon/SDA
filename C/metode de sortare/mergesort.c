#include <stdio.h>
#define NMAX 1000

void mergesort(int a[], int left, int right)
{
    // Cazul banal sau cazul imposibil
    if (left >= right)
        return;
    
    // alegem mijlocul
    int mid = (left + right) / 2;
    // sortam intervalele mai mici
    mergesort(a, left, mid);
    mergesort(a, mid + 1, right);

    // si acum interclasam
    int aux[NMAX];
    int contor_left = left, contor_right = mid + 1;
    int poz = left;
    while (contor_left <= mid || contor_right <= right) {
        // daca prima parte din sir nu mai are elemente
        if (contor_left > mid)
            aux[poz++] = a[contor_right++];
        // daca a doua parte din sir nu mai are elemente
        else if (contor_right > right)
            aux[poz++] = a[contor_left++];
        // altfel luam si punem elementul mai mic
        else if (a[contor_left] < a[contor_right])
            aux[poz++] = a[contor_left++];
        else
            aux[poz++] = a[contor_right++];
    }
    for (int i = left; i <= right; i++)
        a[i] = aux[i];
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
    mergesort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}

/*
    Count sort
    Se bazeaza pe vectori de frecventa
    functioneaza numai daca valorile sunt relativ mici
*/

#include <stdio.h>
#define NMAX 1000

int max(int x, int y)
{
    return (x > y ? x : y);
}
int main()
{
    int n, frecv[NMAX] = {0}, Max = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        // calculam frecventa fiecarui element, respectiv elementul maxim
        frecv[x]++;
        Max = max(x, Max);
    }
    for (int i = 0; i <= Max; i++) {
        int frecventa = frecv[i];
        // Cat timp mai avem elementul i (de cate ori aparea in vectorul initial)
        while (frecventa--) {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}
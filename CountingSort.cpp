#include <CountingSort.h>

void counting_sort(int a[], int n) {
    int max = a[0], s[n];
    for (int i = 0; i < n; i++) 
        if (a[i] > max)
            max = a[i];
    int c[max + 1];
    for (int i = 0; i < max + 1; i++)
        c[i] = 0;
    for (int i = 0; i < n; i++)
        c[a[i]]++;
    for (int i = 1; i < max + 1; i++)
        c[i] = c[i - 1] + c[i];
    for (int i = n - 1; i >= 0; i--) {
        s[c[a[i]] - 1] = a[i];
        c[a[i]]--;
    }
    for (int i = 0; i < n; i++)
        a[i] = s[i];
    return;
}

void counting_sort_compare(int a[], int n, int& compare) {
    compare = 0;
    int max = a[0], s[n];
    for (int i = 0; ++compare && i < n; i++) 
        if (a[i] > max)
            max = a[i];
    int c[max + 1];
    for (int i = 0; ++compare && i < max + 1; i++)
        c[i] = 0;
    for (int i = 0; ++compare && i < n; i++)
        c[a[i]]++;
    for (int i = 1; ++compare && i < max + 1; i++)
        c[i] = c[i - 1] + c[i];
    for (int i = n - 1; ++compare && i >= 0; i--) {
        s[c[a[i]] - 1] = a[i];
        c[a[i]]--;
    }
    for (int i = 0; ++compare && i < n; i++)
        a[i] = s[i];
    return;
}
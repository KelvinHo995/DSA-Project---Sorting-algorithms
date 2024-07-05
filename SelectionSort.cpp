#include "SelectionSort.h"

void selection_sort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min])
                min = j;
        }
        swap(a[i], a[min]);
    }
    return;
}

void selection_sort_compare( int a[], int n, long long & compare) {
    compare = 0;
    for (int i = 0; ++compare && i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; ++compare && j < n; j++) {
            if (++compare && a[j] < a[min])
                min = j;
        }
        swap(a[i], a[min]);
    }
    return;
}


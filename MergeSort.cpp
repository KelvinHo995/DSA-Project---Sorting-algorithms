#include "MergeSort.h"

void merge_sort(int a[], int n) {
    if (n > 1) {
        int *b = new int [n /2], *c = new int [n - n/2];
        for (int i = 0; i < n/2; i++)
            b[i] = a[i];
        for (int j = n/2; j < n; j++)
            c[j - n/2] = a[j];
        merge_sort(b, n/2);
        merge_sort(c, n - n/2);
        merge(b, c, a, n/2, n - n/2);
        delete [] b;
        delete [] c;
    }
    return;
}

void merge(int b[], int c[], int a[], int p, int q) {
    int i = 0, j = 0, k = 0;
    while (i < p && j < q) {
        if (b[i] <= c[j]) {
            a[k] = b[i];
            i++;
        }
        else {
            a[k] = c[j];
            j++;
        }
        k++;
    }
    if (i == p) {
        while (j < q) {
            a[k] = c[j];
            j++;
            k++;
        }
    }
    else {
        while (i < p) {
            a[k] = b[i];
            i++;
            k++;
        }
    }
    return;
}

void merge_sort_compare(int a[], int n, long long & compare) {
    compare = 0;
    if (++compare && n > 1) {
        int *b = new int [n /2], *c = new int [n - n/2];
        for (int i = 0; ++compare && i < n/2; i++)
            b[i] = a[i];
        for (int j = n/2; ++compare && j < n; j++)
            c[j - n/2] = a[j];
        merge_sort_compare(b, n/2, compare);
        merge_sort_compare(c, n - n/2, compare);
        merge_compare(b, c, a, n/2, n - n/2, compare);
        delete [] b;
        delete [] c;
    }
    return;
}

void merge_compare(int b[], int c[], int a[], int p, int q, long long & compare) {
    int i = 0, j = 0, k = 0;
    while (++compare && i < p && ++compare && j < q) {
        if (++compare && b[i] <= c[j]) {
            a[k] = b[i];
            i++;
        }
        else {
            a[k] = c[j];
            j++;
        }
        k++;
    }
    if (++compare && i == p) {
        while (++compare && j < q) {
            a[k] = c[j];
            j++;
            k++;
        }
    }
    else {
        while (++compare && i < p) {
            a[k] = b[i];
            i++;
            k++;
        }
    }
    return;
}
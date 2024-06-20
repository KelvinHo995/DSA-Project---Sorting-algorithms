#include"quicksort.h"

int partition(int a[], int l, int r){
    int pivot = a[l];
    int i = l - 1, j = r + 1;
    while(1){
        do{
            ++i;
        }while(a[i] < pivot);
        do{
            j--;
        }while(a[j] > pivot);
        if(i < j)
            swap(a[i], a[j]);
        else
            return j;
    }
    return -1;
}

void quick_sort_recursive(int a[], int l, int r){
    if(l < r){
        int pa = partition(a, l, r);
        quick_sort_recursive(a, l, pa);
        quick_sort_recursive(a, pa + 1, r);
    }
}

void quick_sort(int a[], int n){
    quick_sort_recursive(a, 0, n - 1);
}

int partition_compare(int a[], int l, int r, long long &count_compare){
    int pivot = a[l];
    int i = l - 1, j = r + 1;
    while(1){
        do{
            ++i;
        }while(++count_compare && a[i] < pivot);
        do{
            j--;
        }while(++count_compare && a[j] > pivot);
        if(++count_compare && i < j)
            swap(a[i], a[j]);
        else
            return j;
    }
    return -1;
}

void quick_sort_recursive_compare(int a[], int l, int r, long long &count_compare){
    if(++count_compare && l < r){
        int pa = partition_compare(a, l, r, count_compare);
        quick_sort_recursive_compare(a, l, pa, count_compare);
        quick_sort_recursive_compare(a, pa + 1, r, count_compare);
    }
}
void quick_sort_compare(int a[], int n, long long &count_compare){
    count_compare = 0;
    quick_sort_recursive_compare(a, 0, n - 1, count_compare);
}
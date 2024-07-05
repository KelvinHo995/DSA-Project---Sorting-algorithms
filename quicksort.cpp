#include"quicksort.h"

int median_of_three_partition(int a[],int l, int r) {
    int x = a[l], y = a[(r - l) / 2 + l], z = a[r - 1], i = l - 1, j = r;
    if (y > x && y < z || y > z && y < x ) x = y;
    else if (z > x && z < y || z > y && z < x ) x=z;
    while (1) {
        do  {j--;} while (a[j] > x);
        do  {i++;} while (a[i] < x);
        if  (i < j) swap(a[i], a[j]);
        else return j+1;
    }
    return -1;
}
void quick_sort_recursive(int a[], int l, int r){
    if(l < r){
        int pa = median_of_three_partition(a, l, r);
        quick_sort_recursive(a, l, pa - 1);
        quick_sort_recursive(a, pa + 1, r);
    }
}

void quick_sort(int a[], int n){
    quick_sort_recursive(a, 0, n - 1);
}

int median_of_three_partition_compare(int a[], int l, int r, long long &count_compare) {
    int x = a[l], y = a[(r - l) / 2 + l], z = a[r - 1], i = l - 1, j = r;
    if (++count_compare && y > x && ++count_compare && y < z ||++count_compare && y > z && ++count_compare && y < x ) x = y;
    else if (++count_compare && z > x && ++count_compare &&z < y || ++count_compare && z > y && ++count_compare && z < x ) x=z;
    while (1) {
        do  {j--;} while (++count_compare && a[j] > x);
        do  {i++;} while (++count_compare && a[i] < x);
        if  (++count_compare && i < j) swap(a[i], a[j]);
        else return j+1;
    }
    return -1;
}

void quick_sort_recursive_compare(int a[], int l, int r, long long &count_compare){
    if(++count_compare && l < r){
        int pa = median_of_three_partition_compare(a, l, r, count_compare);
        quick_sort_recursive_compare(a, l, pa - 1 , count_compare);
        quick_sort_recursive_compare(a, pa + 1, r, count_compare);
    }
}
void quick_sort_compare(int a[], int n, long long &count_compare){
    count_compare = 0;
    quick_sort_recursive_compare(a, 0, n - 1, count_compare);
}
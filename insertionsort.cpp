#include"insertionsort.h"

void insertion_sort(int a[], int n){
    for(int i = 1; i < n; i++){
        int key = a[i];
        int j = i - 1;
        while(j >= 0 && key < a[j]){
            a[j + 1] = a[j];
            j--;
        }
        swap(a[j + 1], key);
    }
}

void insertion_sort_compare(int a[], int n, long long &count_compare){
    count_compare =  0;
    for(int i = 1; i < n && ++count_compare; i++){
        int key = a[i];
        int j = i - 1;
        while(++count_compare && j >= 0 && ++count_compare && key < a[j]){
            a[j + 1] = a[j];
            j--;
        }
        swap(a[j + 1], key);
    }
}
#include"bubblesort.h"

void bubble_sort(int a[], int n){
    bool swapped;
    for(int i = 0; i < n - 1; i++){
        swapped = false;
        for(int j = 0; j < n - 1 - i; j++){
            if(a[j] > a[j + 1]){
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }
        if(swapped == false)
            break;
    }
}

void bubble_sort_compare(int a[], int n, long long &count_compare){
    count_compare = 0;
    bool swapped;
    for(int i = 0; ++count_compare && i < n - 1  ; i++){
        swapped = false;
        for(int j = 0; ++count_compare && j < n - 1 - i  ; j++){
            if(++count_compare && a[j] > a[j + 1]){
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }
        if(swapped == false)
            break;
    }
}
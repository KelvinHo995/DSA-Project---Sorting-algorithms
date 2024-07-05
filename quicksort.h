#pragma once
#include<iostream>
using namespace std;

int median_of_three_partition(int a[], int l, int r);
void quick_sort_recursive(int a[], int l, int r);
void quick_sort(int a[], int n);

int median_of_three_partition_compare(int a[], int l, int r, long long &count_compare);
void quick_sort_recursive_compare(int a[], int l, int r, long long &count_compare);
void quick_sort_compare(int a[], int n, long long &count_compare);
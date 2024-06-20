#pragma once

#include <iostream>
#include <math.h>

using namespace std;

void insertion_sort(int a[], int l, int r);
void flash_sort(int a[], int n);
void insertion_sort(int a[], int l, int r, long long & cmp_count);
void flash_sort_compare(int a[], int n, long long & cmp_count);
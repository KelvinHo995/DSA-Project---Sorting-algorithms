#include "shakersort.h"

void shaker_sort(int a[], int n)
{
    int curr = 0;
    int right = n - 1;
    int left = 0;

    while (left < right)
    {
        // left to right
        while (curr <= right - 1)
        {
            if (a[curr] > a[curr + 1])
            {
                std::swap(a[curr], a[curr + 1]);
            }
            curr += 1;
        }
        right -= 1;

        // right to left
        while (curr >= left + 1)
        {
            if (a[curr] < a[curr - 1])
            {
                std::swap(a[curr], a[curr - 1]);
            }
            curr -= 1;
        }
        left += 1;
    }
}

void shaker_sort_compare(int a[], int n, long long &cmp_count)
{
    int curr = 0;
    int right = n - 1;
    int left = 0;

    cmp_count = 1;
    while (left < right)
    {
        cmp_count += 1;
        // left to right
        while (curr <= right - 1)
        {

            cmp_count += 1;
            if (a[curr] > a[curr + 1])
            {
                std::swap(a[curr], a[curr + 1]);
            }
            curr += 1;
        }
        right -= 1;

        // right to left
        cmp_count += 1;
        while (curr >= left + 1)
        {
            cmp_count += 1;
            if (a[curr] < a[curr - 1])
            {
                std::swap(a[curr], a[curr - 1]);
            }
            curr -= 1;
        }
        left += 1;
    }
}

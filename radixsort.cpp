#include "radixsort.h"
int findMax(int arr[], int n)
{
    int m = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > m)
            m = arr[i];
    return m;
}

int countDigits(int n)
{
    int count = 0;
    while (n > 0)
    {
        n /= 10;
        count++;
    }
    return count;
}
int getDigit(int n, int ith_digit_from_rightmost)
{
    int digit = n / (int)(std::pow(10, ith_digit_from_rightmost - 1)) % 10;
    return digit;
}
void countSort(int a[], int n, int ith_digit_from_rightmost, long long &compare)
{
    // digits-frequency tracking
    int copy_a[n];
    int count[10] = {0};

    for (int i = 0; ++compare && i < n; i++)
    {
        int digit = getDigit(a[i], ith_digit_from_rightmost);
        count[digit]++;
    }

    // convert to prefix sum array, each value on count should be the position instead of frequency
    for (int i = 1; ++compare && i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    // place elements into proper position keyed by last digit
    for (int i = n - 1; ++compare && i >= 0; i--)
    {
        int digit = getDigit(a[i], ith_digit_from_rightmost);
        copy_a[count[digit] - 1] = a[i];
        count[digit]--;
    }

    for (int i = 0; ++compare && i < n; i++)
    {
        a[i] = copy_a[i];
    }
}

void countSort(int a[], int n, int ith_digit_from_rightmost)
{
    // digits-frequency tracking
    int copy_a[n];
    int count[10] = {0};
    for (int i = 0; i < n; i++)
    {
        int digit = getDigit(a[i], ith_digit_from_rightmost);
        count[digit]++;
    }

    // convert to prefix sum array, each value on count should be the position instead of frequency
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    // place elements into proper position keyed by last digit
    for (int i = n - 1; i >= 0; i--)
    {
        int digit = getDigit(a[i], ith_digit_from_rightmost);
        copy_a[count[digit] - 1] = a[i];
        count[digit]--;
    }

    for (int i = 0; i < n; i++)
    {
        a[i] = copy_a[i];
    }
}

void radix_sort(int a[], int n)
{

    // get max
    int max = findMax(a, n);

    // get number of digits in max
    int num_digits = countDigits(max);

    // count sort on each digit from rightmost
    int ith_digit_from_rightmost = 1;
    while (ith_digit_from_rightmost <= num_digits)
    {
        countSort(a, n, ith_digit_from_rightmost);
        ith_digit_from_rightmost++;
    }
}

void radix_sort_compare(int a[], int n, long long &compare)
{
    // get max
    compare = n;
    int max = findMax(a, n);

    // get number of digits in max
    int num_digits = countDigits(max);
    compare += num_digits;

    // count sort on each digit from rightmost
    int ith_digit_from_rightmost = 1;
    while (++compare && ith_digit_from_rightmost <= num_digits)
    {
        countSort(a, n, ith_digit_from_rightmost, compare);
        ith_digit_from_rightmost++;
    }
}

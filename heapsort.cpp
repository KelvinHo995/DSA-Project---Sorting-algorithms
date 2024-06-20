#include "heapsort.h"

// heapify a subtree rooted at node i
void heapify_sub_tree(int a[], int n, int i)
{
    // left and right child of node i
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // finding index with largest value among the three
    int lowest = i;

    if (left < n && a[left] < a[lowest])
        lowest = left;
    if (right < n && a[right] < a[lowest])
        lowest = right;

    // if root is not largest, swap
    if (i != lowest)
    {
        std::swap(a[i], a[lowest]);

        // after swapping, update the affected subtree
        heapify_sub_tree(a, n, lowest);
    }
}

// overloaded heapify_sub_tree function to count comparisons
void heapify_sub_tree(int a[], int n, int i, int &compare)
{
    // left and right child of node i
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // finding index with largest value among the three
    int lowest = i;

    compare++;
    if (left < n && a[left] < a[lowest])
        lowest = left;
    compare++;
    if (right < n && a[right] < a[lowest])
        lowest = right;

    // if root is not largest, swap
    compare++;
    if (i != lowest)
    {
        std::swap(a[i], a[lowest]);

        // after swapping, update the affected subtree
        heapify_sub_tree(a, n, lowest, compare);
    }
}

void heap_sort(int a[], int n)
{
    // heapify whole tree, from bottom to top
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify_sub_tree(a, n, i);

    // extract elements one by one
    int result[n];
    for (int i = 0; i < n; i++)
    {
        // get lowest value
        result[i] = a[0];

        // remove lowest value from heap
        a[0] = a[n - i - 1];
        heapify_sub_tree(a, n - i - 1, 0);
    }

    // copy result back to original array
    for (int i = 0; i < n; i++)
        a[i] = result[i];
}

void heap_sort_compare(int a[], int n, int &compare)
{
    compare = 1;
    // heapify whole tree, from bottom to top
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        compare++;
        heapify_sub_tree(a, n, i, compare);
    }

    // extract elements one by one
    int result[n];
    compare++;
    for (int i = 0; i < n; i++)
    {
        compare++;
        // get lowest value
        result[i] = a[0];

        // remove lowest value from heap
        a[0] = a[n - i - 1];
        heapify_sub_tree(a, n - i - 1, 0, compare);
    }

    // copy result back to original array
    compare++;
    for (int i = 0; i < n; i++)
    {
        compare++;
        a[i] = result[i];
    }
}

#include "flashsort.h"

void insertion_sort(int a[], int l, int r)
{
    for(int i = l; i < r; i++)
    {
        int temp = a[i];

        int j = i - 1;
            while(j >= 0 and temp < a[j])
            {
                a[j + 1] = a[j];
                j -= 1;
            }

        a[j + 1] = temp;
    }
}

void insertion_sort(int a[], int l, int r, long long & cmp_count)
{
    for(int i = l; ++cmp_count and i < r; i++)
    {
        int temp = a[i];
        
        int j = i - 1;
            while(++cmp_count and j >= 0 and ++cmp_count and temp < a[j])
            {
                a[j + 1] = a[j];
                j -= 1;
            }

        a[j + 1] = temp;
    }
}

void flash_sort(int a[], int n)
{
    // Step 1: find minimal and maximal value
    int min_value = a[0];
    int max_value = a[0];
    int max_id = 0;
    for(int i = 0; i < n; i++)
    {
        if(a[i] > max_value)
            max_value = a[i], max_id = i;
        if(a[i] < min_value)
            min_value = a[i];
    }   

    // If min = max then no need to sort
    if(min_value == max_value)
        return;
    
    // Step 2: Divide array into m buckets whereas m = 0.45n
    const int m = max(int(floor(0.45 * n)), 1);

    auto get_bucket_id = [m, min_value, max_value](int value) -> int
    {
        return m * (value - min_value) / (max_value - min_value + 1);
    };

    // Step 3: Count elements in each bucket
    int *cnt = new int [m] {0};
    // int *cnt_copy = new int [m]; // all cnt will go back to 0 
    for(int i = 0; i < n; i++)
    {
        int id = get_bucket_id(a[i]);
        cnt[id]++;
    }

    // Step 4: Calculate cummulative sums of the buckets
    for(int i = 1; i < m; i++)
        cnt[i] += cnt[i - 1];

    // Step 5: Rearrange elements to their buckets
    swap(a[max_id], a[0]);
    int cur_bucket = m - 1; //default bucket that we are trying to rearrange is the biggest one
    int cur = 0; // 0 -> cur has been placed in the correct bucket
    int move = 0; // maximum number of move is n - 1
    int temp;
    while(move < n - 1) // i won't explain this it's just too long
    {
        while(cur > cnt[cur_bucket] - 1)
        {
            cur++;
            cur_bucket = get_bucket_id(a[cur]);
        }
        temp = a[cur];
        if(cur_bucket < 0) break;
        while(cur != cnt[cur_bucket])
        {
            cur_bucket = get_bucket_id(temp);
            cnt[cur_bucket]--;
            swap(temp, a[cnt[cur_bucket]]);
            ++move;
        }
    }

    // Step 6: Insertion sort all the buckets (sort each bucket not the entire array at once)
    for(int bucket = 0; bucket < m; bucket++)
    {
        int l = cnt[bucket];
        int r = (bucket == m - 1 ? n : cnt[bucket + 1]);
        insertion_sort(a, l, r);
    }

    delete [] cnt;
}

void flash_sort_compare(int a[], int n, long long & cmp_count)
{
    // Step 1: find minimal and maximal value
    int min_value = a[0];
    int max_value = a[0];
    int max_id = 0;
    for(int i = 0; ++cmp_count and i < n; i++)
    {
        if(++cmp_count and a[i] > max_value)
            max_value = a[i], max_id = i;
        if(++cmp_count and a[i] < min_value)
            min_value = a[i];
    }   

    // If min = max then no need to sort
    if(++ cmp_count && min_value == max_value)
        return;
    
    // Step 2: Divide array into m buckets whereas m = 0.45n
    const int m = max(int(floor(0.45 * n)), 1);

    auto get_bucket_id = [m, min_value, max_value](int value) -> int
    {
        return m * (value - min_value) / (max_value - min_value + 1);
    };

    // Step 3: Count elements in each bucket
    int *cnt = new int [m] {0};
    // int *cnt_copy = new int [m]; // all cnt will go back to 0 
    for(int i = 0; ++cmp_count and i < n; i++)
    {
        int id = get_bucket_id(a[i]);
        cnt[id]++;
    }

    // Step 4: Calculate cummulative sums of the buckets
    for(int i = 1; ++cmp_count and i < m; i++)
        cnt[i] += cnt[i - 1];

    // Step 5: Rearrange elements to their buckets
    swap(a[max_id], a[0]);
    int cur_bucket = m - 1; //default bucket that we are trying to rearrange is the biggest one
    int cur = 0; // 0 -> cur has been placed in the correct bucket
    int move = 0; // maximum number of move is n - 1
    int temp;
    while(++cmp_count and move < n - 1) // i won't explain this it's just too long
    {
        while(++cmp_count and cur > cnt[cur_bucket] - 1)
        {
            cur++;
            cur_bucket = get_bucket_id(a[cur]);
        }
        temp = a[cur];
        if(++cmp_count and cur_bucket < 0) break;
        while(++cmp_count and cur != cnt[cur_bucket])
        {
            cur_bucket = get_bucket_id(temp);
            cnt[cur_bucket]--;
            swap(temp, a[cnt[cur_bucket]]);
            ++move;
        }
    }

    // Step 6: Insertion sort all the buckets (sort each bucket not the entire array at once)
    for(int bucket = 0; ++cmp_count and bucket < m; bucket++)
    {
        int l = cnt[bucket];
        int r = (bucket == m - 1 ? n : cnt[bucket + 1]);
        insertion_sort(a, l, r, cmp_count);
    }

    delete [] cnt;
}
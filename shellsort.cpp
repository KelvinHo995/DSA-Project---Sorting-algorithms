void shell_sort_compare(int array[], int n, int &compare)
{
    // Sort elements at n/2, n/4, n/8, ... intervals
    compare = 1;
    for (int interval = n / 2; interval > 0; interval /= 2)
    {
        compare++;
        for (int i = interval; i < n; i += 1)
        {
            compare++;
            int temp = array[i];
            int j;

            for (j = i; j >= interval && array[j - interval] > temp; j -= interval)
            {
                compare += 2;
                array[j] = array[j - interval];
            }
            array[j] = temp;
        }
    }
};
void shell_sort(int array[], int n)
{
    // Sort elements at n/2, n/4, n/8, ... intervals
    for (int interval = n / 2; interval > 0; interval /= 2)
    {
        for (int i = interval; i < n; i += 1)
        {
            int temp = array[i];
            int j;

            for (j = i; j >= interval && array[j - interval] > temp; j -= interval)
            {
                array[j] = array[j - interval];
            }
            array[j] = temp;
        }
    }
}
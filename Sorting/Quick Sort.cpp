// https://www.codingninjas.com/codestudio/problems/quick-sort_983625?leftPanelTab=2

// 1at way
/*
    Time Complexity: O(N ^ 2)
    Space Complexity: O(N)

    Where 'N' is the size of the array.
*/

void quickSortHelper(vector<int> &arr, int l, int r)
{
    // Base case.
    if(l >= r)
    {
        return;
    }

    int pivot = arr[r];

    int i = l, j = l;

    // Split the array.
    while(i < r)
    {
        if(arr[i] <= pivot)
        {
            swap(arr[i], arr[j]);
            j++;
        }
        i++;
    }

    swap(arr[r], arr[j]);

    // Call quickSortHelper on both halves.
    quickSortHelper(arr, l, j - 1);

    quickSortHelper(arr, j + 1, r);
}

vector<int> quickSort(vector<int> arr)
{
    quickSortHelper(arr, 0, arr.size() - 1);

    return arr;
}

#include <stdio.h>
#include <stdbool.h>
void merge(int *arr, int s, int e)
{
    int mid = (e - s) / 2 + s;
    int len1 = mid - s + 1;
    int len2 = e - mid;
    int left[len1];
    int right[len2];
    int mainArrayInd = s;
    // chota vala element sb left me aa gaye
    for (int i = 0; i < len1; i++)
        left[i] = arr[mainArrayInd++];
    // mainArrayInd = mid+1;
    // bada vala element sb right me aa gaye
    
    for (int i = 0; i < len2; i++)
        right[i] = arr[mainArrayInd++];
    int index1 = 0; 
    int index2 = 0;
    mainArrayInd = s;
    // merging two sorted array
    while (index1 < len1 && index2 < len2)
    {
        if (left[index1] < right[index2])
            arr[mainArrayInd++] = left[index1++];
        else
            arr[mainArrayInd++] = right[index2++];
    }
    while (index1 < len1)
        arr[mainArrayInd++] = left[index1++];
    while (index2 < len2)
        arr[mainArrayInd++] = right[index2++];
}
void mergeSort(int *arr, int s, int e)
{
    if (s >= e)
        return;
    int mid = (e - s) / 2 + s;
    // left array partition
    mergeSort(arr, s, mid);
    // right array partition
    mergeSort(arr, mid + 1, e);
    // merge both array;
    merge(arr, s, e);
}
int main()
{
    int arr[14] = {1, 5, 6, 3, 0, 4, 3, 0, 0, 1, 8, 5, 7, 1};
    int n = 14;
    mergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}
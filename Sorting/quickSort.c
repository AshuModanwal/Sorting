#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
int partition(int *arr, int s, int e){
    int pivot = arr[s];
    int cnt = 0;
    for(int i=s+1; i<=e; i++)
    {
        if(arr[i]<=pivot)
            cnt++;
    } 
    int pivotInd = s + cnt;
    // take pivot to right place;
    int temp = arr[pivotInd];
    arr[pivotInd] = arr[s];
    arr[s] = temp;
    // pivot ke left me pivot se chota & pivot ke right me pivot se bada b 
    int i = s, j = e;
    while(i<pivotInd && j>pivotInd){
        while(arr[i]<=pivot)
            i++;
        while(arr[j]>pivot)
            j--;
        if(i<pivotInd && j>pivotInd){ 
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    return pivotInd;

}
void quickSort(int *arr, int s, int e){
    if(s>=e)
        return;
    int p = partition(arr, s, e);
    // left ko sort karo
    quickSort(arr, s, p-1);
    // right ko sort karo
    quickSort(arr, p+1, e);
}
int main(){
    int arr[14] = {1, 5, 6, 3, 0, 4, 3, 0, 0, 1, 8, 5, 7, 1};
    int n = 14;
    quickSort(arr, 0, n-1);
    for (int i = 0; i < 14; i++)
    {
        printf("%d  ", arr[i]);
    }
    return 0;
}
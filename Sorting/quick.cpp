#include<bits/stdc++.h>
using namespace std;

// Function to partition the array
int partition(vector<int> &arr, int s, int e){
    int pivot = arr[s];
    int cnt = 0;
    
    // Count the number of elements less than or equal to pivot
    for(int i = s + 1; i <= e; i++){
        if(arr[i] <= pivot)
            cnt++;
    }
    
    int pivotInd = s + cnt;
    
    // Swap the pivot element to its correct position
    swap(arr[s], arr[pivotInd]);
    int i = s;
    int j = e;
    
    // Move elements smaller than pivot to the left and larger to the right
    while(i <= pivotInd && j > pivotInd){
        while(arr[i] <= arr[pivotInd])
            i++;
        while(arr[j] > arr[pivotInd])
            j--;
        if(i <= pivotInd && j > pivotInd){
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    return pivotInd;
}

// Function to print the array
void print(vector<int> &arr){
    for(auto i: arr){
        cout<<i<<" ";
    }
}

// Quicksort function
void quick(vector<int> &arr, int s, int e){
    if(s >= e){
        return;
    }
    int p = partition(arr, s, e);
    quick(arr, s, p - 1);
    quick(arr, p + 1, e);
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int s = 0;
    int e = n - 1;
    quick(arr, s, e);
    print(arr);
    return 0;
}

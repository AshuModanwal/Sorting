#include<bits/stdc++.h>
using namespace std;

// Function to merge two sorted arrays
void merge(vector<int> &arr, int s, int e){
    // Calculate mid index
    int mid = (e-s)/2 + s;
    int len1 = mid-s+1;
    int len2 = e-mid;
    
    // Create temporary arrays to store the left and right halves
    int *left = new int[len1];
    int *right  = new int[len2];
    
    int mainInd = s;

    // Copy data to temporary arrays left[] and right[]
    for(int i=0; i<len1; i++){
        left[i] = arr[mainInd++];
    }

    for(int i=0; i<len2; i++){
        right[i] = arr[mainInd++];
    }

    mainInd = s;
    int i = 0;
    int j = 0;

    // Merge the two sorted arrays back into arr
    while(i<len1 && j<len2){
        if(left[i]<right[j]){
            arr[mainInd++] = left[i++];
        }
        else{
            arr[mainInd++] = right[j++];
        }
    }

    // Copy any remaining elements from left and right arrays
    while(i<len1){
        arr[mainInd++] = left[i++];
    }

    while(j<len2){
        arr[mainInd++] = right[j++];
    }

    // Free memory allocated for temporary arrays
    delete[] left;
    delete[] right;
}

// Recursive function for merge sort
void mergeSort(vector<int> &arr, int s, int e){
    if(s>=e){
        return ;
    }

    // Calculate mid index
    int mid = (e-s)/2 + s;
    
    // Recursively sort the left and right halves
    mergeSort(arr, s, mid);
    mergeSort(arr, mid+1, e);
    
    // Merge the sorted halves
    merge(arr, s, e);
}

// Function to print the array
void print(vector<int> &arr){
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int s = 0;
    int e = n-1;

    // Call merge sort function
    mergeSort(arr, s, e);

    // Print the sorted array
    print(arr);

    return 0;
}

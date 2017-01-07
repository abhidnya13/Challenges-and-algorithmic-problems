#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void swap(int &a, int &b) {
    int temp;
    temp =a ;
    a=b;
    b=temp;
}
int partition(int *arr, int l, int hi ) {
    int pivot = arr[hi];
    int p = l;
    for(int i=l;i<=hi-1;i++) {
        if(arr[i]<=pivot) {
            swap(arr[i],arr[p]);
            p++;
        }
    }
    swap(arr[hi],arr[p]);
    return p;
}
void quicksort(int *arr, int l, int hi) {
    if(l<hi) {
        int p = partition(arr,l,hi);
        quicksort(arr,l,p-1);
        quicksort(arr,p+1,hi);
    }
}
void printarr(int *arr,int n) {
    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
}
int main() {
    int n, *arr;
    cin>>n;
    arr = new int[n];
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    quicksort(arr,0,n-1);
    int diff = 1000000000;
    for(int i=0;i<n;i++) {
        if((abs(arr[i]-arr[i+1])) < diff )
            diff = (abs(arr[i]-arr[i+1]));
    }
    int res[n],j=0;
    for(int i=0;i<n;i++) {
        if((abs(arr[i]-arr[i+1]))==diff ) {
            res[j] = arr[i];
            j++;
            res[j] = arr[i+1];
            j++;
        }
    }
    quicksort(res,0,j-1);
    printarr(res,j);
    return 0;
}

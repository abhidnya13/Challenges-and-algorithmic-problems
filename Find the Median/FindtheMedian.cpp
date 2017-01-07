#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
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
    int p = partition(arr,0,n-1);
    if(p==(n/2))
        cout<<arr[p];
    else if(p > n/2) {
        quicksort(arr,0,p-1);
        cout<<arr[n/2];
    }
    else {
        quicksort(arr,p+1,n-1);
        cout<<arr[n/2];
    }
    return 0;
}


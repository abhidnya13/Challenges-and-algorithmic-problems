#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n;
void swap(int &a,int &b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}    
void printarr(int *ar) {
    for(int i=0;i<n;i++) {
        cout<<ar[i]<<" ";
    }
    cout<<endl;
}
void quicksort(int *ar, int l, int hi){
    int pivot;
    pivot = ar[hi];
    int j=l;
    if(l<hi){
        for(int i=l;i<=hi-1;i++) {
            if(ar[i]<pivot) {
                swap(ar[i],ar[j]);
                j+=1;
            }               
        }
        swap(ar[j],ar[hi]);
    printarr(ar);
    quicksort(ar,l,j-1);
    quicksort(ar,j+1,hi);
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int *ar;
    cin>>n;
    ar = new int[n];
    for(int i =0;i<n ;i++){
        cin>>ar[i];
    }
    quicksort(ar,0,n-1);
    return 0;
}

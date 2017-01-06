#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int cnti,cntq;
void insertionSort(int * ar, int ar_size) {
    for (int i = 1; i < ar_size; i++) {
        int j = i;
        int value = ar[i];
        while (j > 0 && ar[j-1] > value) {
            ar[j] = ar[j-1];
            j--;
            cnti++;
        }
        ar[j] = value;
    }
}
void swap(int &a,int &b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}
int partition(int *ar, int l, int hi) {
  int pivot = ar[hi];
  int s=l;
  for( int i = l ; i < hi ; i++ )
  {
   if( ar[i] <= pivot )
   { 
       swap(ar[i],ar[s]);
       cntq++;
       s++;
   } 
  }
  swap(ar[s],ar[hi]);
  cntq++ ;
  return s;
}

void quicksort(int *ar, int l, int hi){
    if( l < hi )
    {
        int j = partition(ar,l,hi);
        quicksort(ar,l,j-1);
        quicksort(ar,j+1,hi);
    }
}

int main() {
    //Enter your code here. Read input from STDIN. Print output to STDOUT    
    int n;
    cin>>n;
    int ar[n],arq[n];
    for(int i =0;i<n ;i++){
        cin>>ar[i];
        arq[i]= ar[i];
    }
    quicksort(arq,0,n-1);
    insertionSort(ar,n);        
    cout<<cnti-cntq;
    return 0;
}

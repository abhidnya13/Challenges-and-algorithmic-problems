#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int quickselect(int *arr, int d, int size, int low){
    if(size==1)
        return arr[size-1];
    int n = rand()%size;
    int m = arr[n];
    int l=0,g=0,e=0;
    int less[size],greater[size],equal[size];
    for(int i=low;i<low+size;i++) {
        if(arr[i]>m){
            greater[g] = arr[i];
            g++;
        }
        else if(arr[i]<m) {
            less[l] = arr[i];
            l++;
        }
        else {
            equal[e] = arr[i];
            e++;
        }
    }
    if(d<=l)
        return quickselect(less,d,l,0);
    else if(d<= l+e)
        return m;
    else
        return quickselect(greater, d-l-e,g,0);
}
void printarr(int *arr,int n) {
    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main() {
    int n,d,t;
    cin>>n>>d;
    int arr[n];
    for(int i=0;i<n;i++) 
        cin>>arr[i];
    int med,med1,low=0,cnt=0;
    float mede;
    if(d%2!=0) {
        for(int i=d;i<n;i++) {
            med = quickselect(arr,((d/2)+1),d,low);
            low++;
            if(arr[d]>= 2*med)
                cnt++;
        }
    }
    else {
        for(int i=d;i<n;i++) {
            med = quickselect(arr,((d/2)+1),d,low);
            med1 = quickselect(arr,(d/2),d,low);
            low++;
            mede = (float(med+med1)/float(2));
            if(arr[d]>= 2*mede)
                cnt++;
        }
    }
    cout<<cnt;    
}


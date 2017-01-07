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
    int m = arr[low];
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
    else if(d<=l+e)
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
float countingsort(int *arr,int low,int size) {
    int total=0;
    int count[201] ={0};
    long int cumu[201] = {0};
    int x= low+size;
    for(int i=low;i<x;i++) {
        count[arr[i]]++;
    }
    for(int i=0;i<201;i++) {
        if(count[i]!=0) {
            total+=count[i];
        }
        cumu[i] = total;
    }
    int med,med1,flag=0;
    if(size%2!=0) {
        for(int i=0;i<201;i++) {
        if(cumu[i]> (size/2))
            return i;
        }    
    }
    else{
        for(int i=0;i<201;i++) {
            if((cumu[i]==(size/2))&&(flag==0)) {
                med=i;
                flag=1;
            }
            if(cumu[i]>(size/2)) {
                med1=i;
                if(flag==0)
                    med=i;
                return ((float(med+med1))/float(2));
            }
                
        }
    }
    
    return 0;
}

int main() {
    int n,d,t;
    cin>>n>>d;
    int arr[n];
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    int low=0,cnt=0;
    float med;
    for(int i=d;i<n;i++) {
        med = countingsort(arr,low,d);
        low++;
        if(arr[i]>= (2*med))
            cnt++;
    }
    cout<<cnt;    
}

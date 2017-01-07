#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
unsigned int countingsort(unsigned int *arr,unsigned int low,unsigned int size) {
    unsigned int total=0;
    unsigned int count[201]={0};
    unsigned int x=low+size,i;
    for(i=low;i<x;i++)
        count[arr[i]]++;
    unsigned int med,med1,flag=0;
    if(size%2!=0) {
        for(i=0;i<201;i++) {
            total+=count[i];
            if(total>(size>>1))
                return i<<1;
        }    
    }
    else{
        for(i=0;i<201;i++) {
            total+=count[i];
            if((total==(size>>1))&&(flag==0)) {
                med=i;
                flag=1;
            }
            if(total>(size>>1)) {
                med1=i;
                if(flag==0)
                    med=i;
                return (med+med1);
            }     
        }
    }
    return 0;
}
int main() {
    unsigned int n,d,i;
    cin>>n>>d;
    unsigned arr[n];
    for(i=0;i<n;i++)
        cin>>arr[i];
    int cnt=0;
    float med;
    for(i=d;i<n;i++) {
        med = countingsort(arr,i-d,d);
        if(arr[i]>=med)
            cnt++;
    }
    cout<<cnt;    
}

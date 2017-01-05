#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n,s,ans;
    cin>>s>>n;
    int *arr;
    arr = new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(arr[i]==s)
        {
            cout<<i;
            break;
        }   
    }
    
    return 0;
}

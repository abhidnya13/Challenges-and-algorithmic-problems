#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int main() {
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    map <int,int> occ;
    long long int n,temp;
    cin>>n;
    for(long long int i=0;i<n;i++) {
        cin>>temp;
        int cnt = occ[temp];
        cnt++;
        occ[temp] = cnt;
    }
    for(int i=0;i<100;i++)
        cout<<occ[i]<<" ";
    return 0;
}


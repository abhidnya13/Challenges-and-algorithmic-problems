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
    int n,temp;
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>temp;
        int cnt = occ[temp];
        cnt++;
        occ[temp] = cnt;
    }
    for(int i=0;i<100;i++){
        if(occ[i]!=0)
            {
            for(int j=0;j<occ[i];j++)
                cout<<i<<" ";
        }
    }
    return 0;
}


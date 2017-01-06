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
    int n,temp,cnt=0;
    string a;
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>temp;
        cin>>a;
        int cnt = occ[temp];
        cnt++;
        occ[temp] = cnt;
    }
    for(int i=0;i<100;i++){
        cnt += occ[i];
        cout<<cnt<<" ";
    }
    return 0;
}


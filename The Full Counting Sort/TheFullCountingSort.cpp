#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string.h>
using namespace std;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int count[100], n, tmp;
    memset(count, 0, sizeof(count));
    cin>>n;
    int *key = new int[n];
    string *in = new string[n],*op = new string[n];
    string s;
    for(int i = 0; i < n; i++) {
        cin>>tmp;
        count[tmp]++; 
        cin>>s;
        if(i < n/2) {
            in[i] = '-';
        } else {
            in[i]= s;
        }
        key[i] = tmp; 
    }
    int total = 0;
    for(int i = 0; i < 100; i++) {
        total += count[i];
        count[i] = total;
    }
    for(int i = n-1; i >= 0; i--) {
        op[count[key[i]]-1] = in[i];
        count[key[i]]--;
    }
    for(int i = 0; i < n; i++) {
        cout<<op[i]<<" ";
    }
    return 0;
}


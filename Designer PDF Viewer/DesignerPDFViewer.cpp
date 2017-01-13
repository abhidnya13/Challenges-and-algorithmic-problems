#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    vector<int> h(26);
    for(int h_i = 0;h_i < 26;h_i++){
       cin >> h[h_i];
    }
    string word;
    cin >> word;
    //ASCII of a is 97
    int hmax=0;
    for(int i =0;i<word.length(); i++) {
        if(h[word[i]-97] > hmax)
            hmax = h[word[i]-97];
    }
    cout<<hmax*word.length();
    return 0;
}


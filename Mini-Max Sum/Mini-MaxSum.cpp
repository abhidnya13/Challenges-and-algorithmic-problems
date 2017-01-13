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
    long int arr[5];
    long int sum=0;
    long int max=0;
    long int min=10000000000;
    long int e;
    cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4];
    for(int i=0;i<5;i++) {
        if(arr[i] < min)
            min = arr[i];
        if(arr[i] > max)
            max = arr[i];
        sum += arr[i];
    }
    cout<<sum-max<<" "<<sum-min;
    
    return 0;
}


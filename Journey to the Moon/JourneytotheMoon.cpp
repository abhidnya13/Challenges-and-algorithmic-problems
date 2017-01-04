#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector> 
#include <list>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <ctime>
#include <cassert>

using namespace std;
int N,I,a,b,visited[100000],cnt;
set<int> G[100000];
  
queue<int> Q;
set<int>::iterator it;
long long colour(int root) {
    visited[root] = ++cnt;
    Q.push(root);
    long long result = 1;
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for(it = G[u].begin(); it != G[u].end(); it++) {
            int v = *it;
            if(visited[v]==0) {
                visited[v] = cnt;
                result++;
                Q.push(v);
            }
        }
    }
    return result;
}
  
int main() {
    cin >> N >> I;
    for(int i = 0; i < I; i++) {
        cin >> a >> b;
        G[a].insert(b);
        G[b].insert(a);
    }
    long long result = 0;
    long long sum = 0;
    for(int i = 0; i < N; i++)
        if(visited[i]==0) {
            long long x = colour(i);
            result += sum*x;
            sum += x;
        }
    cout << result << endl;
}


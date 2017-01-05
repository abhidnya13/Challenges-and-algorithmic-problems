#include <bits/stdc++.h>
using namespace std;
void printarr(vector <int> ar,int size) {
    for(int i=0;i<size;i++){
        cout<<ar[i]<<" ";
    }
    cout<<endl;
}
vector<int> quickSort(vector <int> &ar) {
    int pivot = ar[0];
    vector <int> left,right,equal,res;
    for(int i=0;i<ar.size();i++){
       if(ar[i]<pivot)
           left.push_back(ar[i]);
       else if(ar[i]>pivot)
           right.push_back(ar[i]);
       else
           equal.push_back(ar[i]);
    }
    if(left.size()>1)
        left = quickSort(left);
    if(right.size()>1)
        right = quickSort(right);
    res.reserve( left.size() + right.size() + equal.size()); // preallocate memory
    res.insert( res.end(), left.begin(), left.end() );
    res.insert( res.end(), equal.begin(), equal.end() );
    res.insert( res.end(), right.begin(), right.end() );
    printarr(res,res.size());
    return res; 
}

int main()
{
    int n;
    cin >> n;
    vector <int> arr(n);
    for(int i = 0; i < (int)n; ++i) {
        cin >> arr[i];
    }
    quickSort(arr);
    return 0;
}

#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <iostream>
using namespace std;
int _ar_size,cnt;
void insertionSort(int * ar, int ar_size) {
    for (int i = 1; i < ar_size; i++) {
        int j = i;
        int value = ar[i];
        while (j > 0 && ar[j-1] > value) {
            ar[j] = ar[j-1];
            j--;
            cnt++;
        }
        ar[j] = value;
    }
}
int main(void) {
    cin >> _ar_size;
    //scanf("%d", &_ar_size);
    int _ar[_ar_size], _ar_i;
    for(_ar_i = 0; _ar_i < _ar_size; _ar_i++) { 
        cin >> _ar[_ar_i];
        //scanf("%d", &_ar[_ar_i]); 
    }
   insertionSort(_ar,_ar_i);  
   cout<<cnt;
   return 0;
}

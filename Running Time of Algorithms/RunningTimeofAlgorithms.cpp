#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int _ar_size,cnt;

void insertionSort(int ar_size, int *  ar) {
    int temp = ar[(ar_size-1)];
    for(int i= (ar_size-1);i>=0;i--)
    {
        if(ar[i-1]>temp)
        {
            cnt++;
            ar[i] = ar[i-1];
        }
        else
        {
            ar[i] = temp;
            break;
        }
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
    for(int i=2;i<=_ar_size;i++)
    {
        insertionSort(i,_ar);        
    }
    cout<<cnt;  
   return 0;
}


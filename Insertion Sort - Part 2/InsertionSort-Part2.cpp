#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <iostream>
using namespace std;
int _ar_size;

void printarr(int  *ar)
{
    for(int i=0;i<_ar_size;i++)
        cout<<ar[i]<<" ";
    cout<<endl;
}

void insertionSort(int ar_size, int *  ar) {
    int temp = ar[(ar_size-1)];
    for(int i= (ar_size-1);i>=0;i--)
    {
        if(ar[i-1]>temp)
        {
            ar[i] = ar[i-1];
        }
        else
        {
            ar[i] = temp;
            break;
        }
    }
    printarr(ar);

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
   
   
   return 0;
}


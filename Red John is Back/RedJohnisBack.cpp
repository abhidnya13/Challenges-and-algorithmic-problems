#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int SieveOfEratosthenes(int n)
{
    
    bool prime[n+1];
    memset(prime, true, sizeof(prime));
    for (int p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {
            for (int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }
    int cnt=0;
    for (int p=2; p<=n; p++)
       if (prime[p])
          cnt+=1;
    return cnt;
}
int fact(int n,int st)
{
    if(n > st)
        return n * fact(n - 1,st);
    else
        return 1;
}
int calc(int h,int v)
{
    int tot,temp;
    tot = h+v;
    if(h>v)
    {
        tot = fact(tot,h);
        tot = tot/fact(v,1);
    }   
    else
    {
        tot = fact(tot,v);
        tot = tot/fact(h,1);
    }   
    h-=1;
    v+=4;
    if(h!=0)
    {
        tot = tot + calc(h,v);
    }
    return tot;
}

int main() 
{
    int t;
    cin>>t;
    for(int k=0; k<t;k++)
    {
        int n,h,v,res,fin;
        cin>>n;
        h = n/4;
        v = n%4;
        if(h!=0)
            res = calc(h,v) + 1;
        else
            res = 1;
        fin = SieveOfEratosthenes(res);
        cout<<fin<<endl;       
    }
    
    return 0;
}

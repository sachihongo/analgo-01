   /**
     *	  Nama  : Sachi Hongo
     *	  NPM   : 140810160014
     *	  Kelas : B
     *    Deskripsi : Analisa Algoritma Tilling dengan Running Time
     **/


#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod (int)(1e9+7)

map<ll,ll>m;

ll ans(ll n)
{
    if(n<2)
        return 1;
    if(n==2)
        return 2;
    if(m.find(n)!=m.end())
        return m[n];
    
    ll k = n/2;
    ll ret;
    if(n&1)
    {
        ret = (ans(k)*ans(k+1) + ans(k)*ans(k-1))%mod;
        m[n] = ret;
    }
    else
    {   
        ret = (ans(k-1)*ans(k-1) + ans(k)*ans(k))%mod;
        m[n] = ret;
    }
    
    return ret;
}

int main() {
    int t;
    ll n;
    cout<<"n = ";
    cin>>n;
    cout<<ans(n)<<endl;
}

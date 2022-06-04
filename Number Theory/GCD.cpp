#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll GCD(ll a, ll b)
{
    if(b==0)
    {
        return a;
    }
    else
    {
        return GCD(b,a%b);
    }
}

int main()
{
    ll gcd=GCD(10,45);
    cout<<"GCD : "<<gcd<<endl;
    ll lcm=(10*45)/gcd;
    cout<<"LCM : "<<lcm<<endl;
}

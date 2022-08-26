#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;

long long powerMod(long long number, long long power, long long mod)
{
    LL ret = 0;
    if (power == 0)
        return 1LL % mod;
    if (power == 1)
        return number % mod;
    if (power % 2 == 0)
    {
        ret = powerMod(number, power / 2, mod);
        ret = (ret % mod * ret % mod) % mod;
        return ret % mod;
    }
    else
    {
        ret = powerMod(number, power / 2, mod);
        ret = (ret % mod * ret % mod * number % mod) % mod;
        return ret % mod;
    }
}

int main()
{
    int a,b,mod,power,Big,ans;
    cin>>a>>b>>mod;
    power=mod-2;
    Big=powerMod(b,power,mod);

    ans=((a%mod)*Big)%mod;
    cout<<ans<<endl;
    return 0;
}
----------------------------------------------------------------------------------------------------------
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define endl '\n'

//ll gcd(ll a, ll b) {return __gcd(a,b);}
//ll lcm(ll a, ll b) {return a*(b/gcd(a,b));}

const int N = 1e5+123;
const int MOD = 1e9+7;

int arr[N];
int brr[N];


ll modPow(ll b,ll p,ll mod)
{
    ll res=1;
    while(p>0)
    {
        if(p%2==1)//p=3 b=3^4
        {
            res*=b;
            res%=mod;
        }
        p/=2; //p=1

        b*=b;
        b%=mod;
    }
    return res;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a,b,mod,power,Big,ans;
    cin>>a>>b>>mod;
    power=mod-2;
    Big=modPow(b,power,mod);

    ans=((a%mod)*Big)%mod;
    cout<<ans<<endl;
    return 0;


    return 0;
}


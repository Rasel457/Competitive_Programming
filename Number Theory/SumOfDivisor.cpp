#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;

LL SOD[10000005];

void SumOfDivisors(LL n)
{
    for(int i=1; i<=n;i++)
    {
        for(int j=i ;j<=n ;j+=i)
        {
             SOD[j]+=i;
        }
    }
}


int main()
{
    LL n;
    cin>>n;
    SumOfDivisors(n);
    cout<<SOD[10]<<endl;
}
------------------------------------------------------------------------------------------------------------

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define endl '\n'

ll gcd(ll a, ll b) {return __gcd(a,b);}
ll lcm(ll a, ll b) {return a*(b/gcd(a,b));}

const int N = 1e6+123;
const int MOD = 1e9+7;

bool isPrime[N];
vector<int>prime;

void PrimeGen(ll n)
{
    isPrime[2]=1;
    for(int i=3;i<=n;i+=2)
    {
        isPrime[i]=1;
    }
    for(int i=3;i*i<=n;i+=2)
    {
        if(isPrime[i]==1)
        {
            for(int j=i*i;j<=n;j+=(2*i))
            {
                isPrime[j]=0;
            }
        }
    }
    prime.push_back(2);
    for(int i=3;i<=n;i+=2)
    {
        if(isPrime[i]==1)
        {
            prime.push_back(i);
        }
    }
}

ll SOD(ll n)//4
{
    double res=1;
    for(auto p:prime)//2
    {
        if(1ll*p*p>n)break;
        if(n%p==0)
        {
            ll currSum=1;//2^0+2^1+2^2
            ll powP=1;//2^0->2^1->2^2
            while(n%p==0)
            {
               powP*=p;
               currSum+=powP;
               n/=p;
            }
            res*=currSum;
        }
    }
    if(n>1)
    {
        res*=(1+n);
    }
    return res;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int lim=1e6;
    PrimeGen(lim);

    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        int ans=SOD(n);
        cout<<ans<<endl;

    }

    return 0;
}

// https://www.spoj.com/problems/DIVSUM/
// https://www.spoj.com/problems/DIVSUM2/


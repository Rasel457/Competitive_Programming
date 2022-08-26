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

ll NOD(ll n)
{
    int res=1;
    for(auto p:prime)
    {
        if(1ll*p*p>n)break;
        if(n%p==0)
        {
            int cnt=0;
            while(n%p==0)
            {
                cnt++;
                n/=p;
            }
            res*=cnt+1;
        }
    }
    if(n>1)
    {
        res*=2;
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
        int a,b;
        cin>>a>>b;
        int GCD=gcd(a,b);
        int ans=NOD(GCD);
        cout<<ans<<endl;
    }

    return 0;

}
// https://www.spoj.com/problems/COMDIV/


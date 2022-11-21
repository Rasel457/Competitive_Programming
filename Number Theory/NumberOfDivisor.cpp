#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;

int NOD[10000005];

void NumberOfDivisors(LL n)
{
    for(int i=1; i<=n;i++)
    {
        for(int j=i ;j<=n ;j+=i)
            NOD[j]++;
    }
}

int main()
{
    LL n;
    cin>>n;
    NumberOfDivisors(n);
    cout<<NOD[100]<<endl;
}

https://atcoder.jp/contests/abc172/tasks/abc172_d
------------------------------------------------------------------------------------------------------

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


void genPrime(int n)
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
            for(int j=i*i;j<=n;j+=(2*i))     //Complexity O(n)
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

int NOD(ll n)
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
    genPrime(lim);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<NOD(n)<<endl;
    }
}

// https://www.hackerearth.com/problem/algorithm/number-of-divisors-5/
// https://www.hackerearth.com/problem/algorithm/number-of-divisors-14/
// https://lightoj.com/problem/false-ordering

              


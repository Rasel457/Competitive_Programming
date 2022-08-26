#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define endl '\n'

ll gcd(ll a, ll b) {return __gcd(a,b);}
ll lcm(ll a, ll b) {return a*(b/gcd(a,b));}

const int N = 3e3+123;
const int MOD = 1e9+7;

bool isPrime[N];
vector<int>prime;
vector<int>PrimeFactor[N];

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


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int lim=3e3;//  n=5e6
    genPrime(lim);

    for(auto p:prime)
    {
        for(int i=p;i<=lim;i+=p)
        {
            int n=i;
            while(n>0 && n%p==0)
            {
                PrimeFactor[i].push_back(p);
                n/=p;
            }
        }
    }
    for(int i=2;i<=20;i++)
    {
        cout<<i<<" : ";
        for(auto pf:PrimeFactor[i])
        {
            cout<<pf<<" ";
        }
        cout<<endl;
    }


}

// https://codeforces.com/contest/26/problem/A


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define endl '\n'

ll gcd(ll a, ll b) {return __gcd(a,b);}
ll lcm(ll a, ll b) {return a*(b/gcd(a,b));}

const int N = 1e3+123;
const int MOD = 1e9+7;

bool isPrime[N];
vector<int>prime;

vector<int>PrimePower[N];

int NOD[N];


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

    int lim=1e3;
    genPrime(lim);

    for(auto p:prime)
    {
        for(int i=p;i<=lim;i+=p)
        {
            int n=i;
            int cnt=0;
            while(n%p==0)
            {
                cnt++;
                n/=p;
            }
            PrimePower[i].push_back(cnt);
        }
    }

    for(int i=1;i<=lim;i++)
    {
        NOD[i]=1;
        for(auto pp:PrimePower[i])
        {
            NOD[i]*=pp+1;
        }
    }

    for(int i=1;i<=20;i++)
    {
       cout<<i<<" : "<<NOD[i]<<endl;
    }

}


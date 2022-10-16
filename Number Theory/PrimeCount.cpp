#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define endl '\n'

const int N = 1e6+125;
const int mod = 1000003;
int arr[N];

ll sum=0;
ll prime[N];


void GenPrime(ll n)
{

    prime[0]=0;
    prime[1]=0;
    for(ll i=2;i<=n;i++)
   {
        prime[i]=1;
   }
    for(ll i=2;i*i<=n;i++)
        {
             if(prime[i]==1)
             {
                  for(ll j=2;i*j<=n;j++)
                  {
                      prime[i*j]=0;
                  }
             }
        }
    for(int i=0;i<=n;i++)
    {
        sum+=prime[i];
        prime[i]=sum;

    }

}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int lim=1e6;
    GenPrime(lim);

    int q;
    cin>>q;
    while(q--)
    {
        ll l,r;
        cin>>l>>r;
        cout<<prime[r]-(prime[l-1])<<endl;

    }

    return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define endl '\n'

const int N = 1e6+123;
const int MOD = 1e9+7;

bool isPrime[N];

int PrimeCnt[N];
void genPrime(int n)
{
    n+=10;
    isPrime[2]=1;
    for(int i=3;i<=n;i+=2)
    {
        isPrime[i]=1;
    }
    for(int i=3;i*i<=n;i+=2)
    {
        if(isPrime[i]==1)
        {
            for(int j=i*i;j<=n;j+=(2*i))     //Complexity O(1)
            {
                isPrime[j]=0;
            }
        }

    }
    ll sum=0;
    for(int i=0;i<=n;i++)
    {
        sum+=isPrime[i];
        PrimeCnt[i]=sum;
    }

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
        int l,r;
        cin>>l>>r;
        cout<<PrimeCnt[r]-PrimeCnt[l-1]<<endl;
    }




}

  

// https://www.spoj.com/problems/SIOENES/

//https://vjudge.net/contest/518597#problem/D

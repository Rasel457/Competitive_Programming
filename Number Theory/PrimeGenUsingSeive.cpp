#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define endl '\n'

const int N = 1e8+5;
const int MOD = 1e9+7;

//bitset<N>isPrime; //32 time faster
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


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    genPrime(1e6);

    int n;
    while(cin>>n)
    {
        if(n==0)
        {
            break;
        }
        int p1=-1,p2=-1;
        for(int i=0;i<n;i++)
        {
            if(prime[i]>n)
            {
                break;
            }
            int tp1=prime[i];
            int tp2=n-tp1;
            if(tp2>2 && isPrime[tp2]==1)
            {
                p1=tp1;
                p2=tp2;
                break;
            }
        }
        if(p1==-1)
        {
            cout<<"Goldbach's conjecture is wrong."<<endl;
        }
        else
        {
            cout<<n<<" = "<<p1<<" + "<<p2<<endl;
        }
    }
}

// https://vjudge.net/problem/UVA-543

//problem List
// https://codeforces.com/contest/776/problem/B
// https://www.spoj.com/problems/TDPRIMES/
// https://www.spoj.com/problems/TDKPRIME/
// https://www.spoj.com/problems/SIOENES/
// https://www.spoj.com/problems/HS08PAUL/
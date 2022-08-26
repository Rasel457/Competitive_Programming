#include <bits/stdc++.h>
using namespace std;

void PrimeFact(int n)
{
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            int cnt=0;
            while(n%i==0)
            {
                n/=i;
                cnt++;
            }
            cout<<i<<"^"<<cnt<<",";
        }
    }
    if(n!=1)
    {
        cout<<n<<"^"<<"1";
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        PrimeFact(n);
    }
    return 0;
}

-----------------------------------------------------------------------------------------------
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define endl '\n'

const int N = 1e5+123;
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
            for(int j=i*i;j<=n;j+=(2*i))     //Complexity O(1)
            {
                isPrime[j]=0;
            }
        }

    }
    prime.push_back(2);
    for(int i=3;i<=n;i++)
    {
        if(isPrime[i]==1)
        {
             prime.push_back(i);
        }
    }

}

vector<int> Primefactorization(ll n)
{
    vector<int>res;
    for(auto p:prime)
    {
        if(1ll*p*p>n)break;
        if(n%p==0)
        {
            while(n%p==0)
            {
                res.push_back(p);
                n/=p;
            }
        }
    }
    if(n>1)
    {
        res.push_back(n);
    }
    return res;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int lim=1e5;
    genPrime(lim);

    ll n;
    while(cin>>n)//1e14
    {
        if(n==0)
        {
            break;
        }
        vector<int>ans=Primefactorization(abs(n));

        if(n<0)
        {
            cout<<n<<" = "<<"-1";
            for(auto a:ans)
            {
                cout<<" x "<<a;
            }
            cout<<endl;
        }
        else
        {
            cout<<n<<" = "<<ans[0];
            for(int i=1;i<ans.size();i++)
            {
                 cout<<" x "<<ans[i];
            }
            cout<<endl;
        }

    }



}
// https://vjudge.net/problem/UVA-583

//problem list
// https://vjudge.net/problem/UVA-11466
// https://www.spoj.com/problems/MAIN12B/




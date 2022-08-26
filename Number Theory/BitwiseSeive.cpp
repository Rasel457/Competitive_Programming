#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define endl '\n'

const int N = 5e7+123; //Half of limit
const int MOD = 1e9+7;


bool seive[N];
vector<int>prime;

void SeiveGen(int n)
{
    n+=100;
    for(int i=3;i*i<=n;i+=2)
    {
        if(!seive[i>>1])
        {
            for(int j=i*i;j<=n;j+=(2*i))
            {
                seive[j>>1]=1;
            }
        }

    }
    prime.push_back(2);
    for(int i=3;i<=n;i+=2)
    {
        if(!seive[i>>1])
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

    int lim=1e8;
    SeiveGen(lim);

    //cout<<prime.size()<<endl;
    for(int i=0;i<prime.size();i+=100)
    {
        if(prime[i]<lim)
        {
            cout<<prime[i]<<endl;
        }
    }



}
//https://www.spoj.com/problems/TDPRIMES/

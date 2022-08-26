#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define endl '\n'

const int N = 2e5+5;
const int MOD = 1e9+7;

int arr[N];

vector<int>divisors[1000002];


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j+=i)
        {
            divisors[j].push_back(i);
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<i<<" : ";
        for(auto d:divisors[i])
        {
            cout<<d<<" ";
        }
        cout<<endl;
    }


}

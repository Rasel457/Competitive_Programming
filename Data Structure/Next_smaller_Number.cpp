#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define endl '\n'

ll gcd(ll a, ll b) {return __gcd(a,b);}
ll lcm(ll a, ll b) {return a*(b/gcd(a,b));}

const int N = 2e5+123;
const int MOD = 1e9+7;

ll arr[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    stack<int>st;
    vector<int>v;
    for (int i=n; i>=1; i--)
    {
        while(!st.empty() && st.top()>=arr[i])
        {
            st.pop();
        }
        if(st.empty())
        {
            v.push_back(-1);
        }
        else
        {
            v.push_back(st.top());
        }
        st.push(arr[i]);
    }
    reverse(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }

    return 0;

}
/*
8
3 10 5 1 15 10 7 6
*/


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
    for (int i=1; i<=n; i++)
    {
        while(!st.empty() && st.top()<=arr[i])
        {
            st.pop();
        }
        if(st.empty())
        {
            cout<<"-1 ";
        }
        else
        {
            cout<<st.top()<<" ";
        }
        st.push(arr[i]);
    }

    return 0;

}
/*
8
4 10 5 8 20 15 3 12

6
5 15 20 25 12 20
*/


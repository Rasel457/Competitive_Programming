#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define endl '\n'
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<pii>
#define vll vector<pll>
#define ff first
#define ss second
#define pb push_back
#define PI 2.0 * acos(0.0)
#define mem(a, b) memset(a, b, sizeof(a))
#define forstl(i, s)  for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)// Delete Specific Element from dequeue

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
///   *Set.find_by_order(k)  returns a pointer to the k'th element (0 indexed)
///   Set.order_of_key(k)   returns an integer equal to the number of elements STRICTLY SMALLER than 'k'
template<typename T> using orderSet = tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;


ll gcd(ll a, ll b) {return __gcd(a,b);}
//ll lcm(ll a, ll b) {return a*(b/gcd(a,b));}

int stringTointeger(string str)
{
    int temp = 0;
    for (int i = 0; i < str.length(); i++) {
        temp = temp * 10 + (str[i] - '0');
    }
    return temp;
}


const int N = 1e5+20;
const int MOD = 1e9+7;
const int inf = 2000000000;
const ll infLL = 9000000000000000;
const ld eps=1e-6 ;// 5 decimal point same

ll dp[20][10005];

ll solve(ll idx,ll tar, ll n,vector<int> &a)
{
    if(idx==n)
    {
        if(tar%a[idx]==0)
        {
            return tar/a[idx];
        }
        else
        {
            return 1e9;
        }
    }

    if(dp[idx][tar]!=-1)
    {
        return dp[idx][tar];
    }

    ll not_take=0+solve(idx+1,tar,n,a);
    ll take=INT_MAX;
    if(a[idx]<=tar)
    {
        take=1+solve(idx,tar-a[idx],n,a);
    }
    return dp[idx][tar]=min(take,not_take);
}
int minimumElements(vector<int> &num, int x)
{
    int n=num.size();
    mem(dp,-1);
    int ans=solve(0,x,n-1,num);

    if(ans>=1e9) return -1;
    return ans;
}

//https://www.codingninjas.com/codestudio/problems/minimum-elements_3843091?leftPanelTab=1
#include <bits/stdc++.h> 
#define mem(a, b) memset(a, b, sizeof(a))
#define ll long long int
const int N = 1e5+20;
const int MOD = 1e9+7;
ll dp[N];
int solve(int pos,int n)
{
    if(pos==n)
    {
        return 1;
    }
    if(dp[pos]!=-1)
    {
        return dp[pos];
    }
    if(pos>n)
    {
        return 0;
    }

    int x=solve(pos+1,n);
    int y=solve(pos+2,n);
    dp[pos]=(x+y)%MOD;
    return dp[pos]%MOD;
}


 

ll countDistinctWays(ll nStairs){
    mem(dp,-1);
    return solve(0,nStairs);
}

--------------------------------------------------------------------------------
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


int dp[N];



int solve(int i,int n)
{

    if(i==n)
    {
        return 1;
    }
    if(dp[i]!=-1)
    {
        return dp[i];
    }
    int res1=0,res2=0;
    if(i+1<=n)
    {
        res1=solve(i+1,n);
    }
    if(i+2<=n)
    {
        res2=solve(i+2,n);
    }

    dp[i]=(res1+res2)%MOD;
    return dp[i]%MOD;
}
int countDistinctWays(int n) {
    

    mem(dp,-1);

    return solve(0,n);

}
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
 
 
const int N = 1e2+20;
const int maxn = 1e5+20;
const int MOD = 1e9+7;
const int inf = 2000000000;
const ll infLL = 9000000000000000;
const ld eps=1e-6 ;// 5 decimal point same
 
int w[N],v[N];
ll W,n;
ll dp[N][maxn];
 
ll solve(ll pos,ll curW)
{
    if(pos>n)
    {
        return 0;
    }
    if(dp[pos][curW]!=-1)
    {
        return dp[pos][curW];
    }
    ll res1=0,res2=0;
 
    if(w[pos]+curW<=W)
    {
        res2=v[pos]+solve(pos+1,w[pos]+curW);
    }
    res1=solve(pos+1,curW);
 
 
    return dp[pos][curW]=max(res1,res2);
}
 
 
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
 
    cin>>n>>W;
 
    for(int i=1;i<=n;i++)
    {
        cin>>w[i]>>v[i];
    }
 
    mem(dp,-1);
    cout<<solve(1,0);
 
    return 0;
 
}

//https://atcoder.jp/contests/dp/tasks/dp_d
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define endl '\n'
#define vi vector<int>
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


const int N = 1e4+20;
const int maxn = 120;
const int MOD = 1e9+7;
const int inf = 2000000000;
const ll infLL = 9000000000000000;
const ld eps=1e-6 ;// 5 decimal point same

int dp[2505][2505];
int n;
int a[N];


int solve(int idx,int prev_idx)
{
    if(idx==n)
    {
       return 0;
    }

    if(dp[idx][prev_idx+1]!=-1)
    {
        return dp[idx][prev_idx+1];
    }

    int not_take=solve(idx+1,prev_idx);
    int take=0;
    if(prev_idx==-1 || a[idx]>a[prev_idx])
    {
        take=1+solve(idx+1,idx);
    }

    return dp[idx][prev_idx+1]=max(take,not_take);  // prev_idx+1 because array index can not start -1;
}


void print(int idx,int prev_idx)
{
    if(idx==n)
    {
       return ;
    }
    if(dp[idx][prev_idx+1]==solve(idx+1,prev_idx))
    {
        print(idx+1,prev_idx);
    }
    else
    {
        cout<<a[idx]<<" ";
        print(idx+1,idx);
    }

}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    mem(dp,-1);

    ll ans=solve(0,-1);
    cout<<ans<<endl;

    print(0,-1);


    return 0;
}
/*
8
10 9 2 5 3 7 101 18

6
0 1 0 3 2 3

7
7 7 7 7 7 7 7
*/



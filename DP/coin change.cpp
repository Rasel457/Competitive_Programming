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


const int N = 3e4+20;
const int MOD = 1e9+7;
const int inf = 2000000000;
const ll infLL = 9000000000000000;
const ld eps=1e-6 ;// 5 decimal point same




int coin[]={1,5,10,25,50};
ll dp[6][N];



ll solve(int idx,int target)
{
    if(idx==5 || target==0)
    {
        return (target==0);
    }

    if(dp[idx][target]!=-1)
    {
        return dp[idx][target];
    }

    ll res=0;

    for(int j=0;j<=target;j++)
    {
        if(target-(j*coin[idx])>=0)
        {
            res+=solve(idx+1,target-(j*coin[idx]));
        }
        else
        {
            break;
        }
    }
    return dp[idx][target]=res;

}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int target;
    mem(dp,-1);
    while(cin>>target)
    {

        /*if(target==0)
        {
            break;
        }*/

        ll x=solve(0,target);
        if(x==1)
        {
            cout<<"There is only 1 way to produce "<<target<<" cents change."<<endl;
        }
        else
        {
             cout<<"There are "<<x<<" ways to produce "<<target<<" cents change."<<endl;
        }

    }

    return 0;
}

--------------------------------------------------------------------------------------------------------------
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


const int N = 3e4+20;
const int MOD = 1e9+7;
const int inf = 2000000000;
const ll infLL = 9000000000000000;
const ld eps=1e-6 ;// 5 decimal point same




int a[]={1,5,10,25,50};
ll dp[6][N];



ll solve(int idx,int tar)
{
    if(idx==4)
    {
        return (tar%a[idx]==0);
    }

    if(dp[idx][tar]!=-1)
    {
        return dp[idx][tar];
    }

    ll not_take=solve(idx+1,tar);
    ll take=0;

    if(a[idx]<=tar)
    {
        take=solve(idx,tar-a[idx]);
    }
    return dp[idx][tar]=take+not_take;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int target;
    mem(dp,-1);
    while(cin>>target)
    {

        /*if(target==0)
        {
            break;
        }*/

        ll x=solve(0,target);
        if(x==1)
        {
            cout<<"There is only 1 way to produce "<<target<<" cents change."<<endl;
        }
        else
        {
             cout<<"There are "<<x<<" ways to produce "<<target<<" cents change."<<endl;
        }

    }

    return 0;
}


//https://vjudge.net/problem/UVA-357




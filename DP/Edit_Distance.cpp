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

int dp[1005][1005];

int n,m;

int solve(int idx1,int idx2,string &s1, string &s2)
{
    if(idx1==n)
    {
        return m-idx2;// inset
    }
    if(idx2==m)
    {
        return n-idx1; //Delete;
    }

    if(dp[idx1][idx2]!=-1)
    {
        return dp[idx1][idx2];
    }
    int ans=0;
    if(s1[idx1]==s2[idx2])
    {
        ans=solve(idx1+1,idx2+1,s1,s2);
    }
    else
    {
        int val1=1+solve(idx1,idx2+1,s1,s2); //Insert
        int val2=1+solve(idx1+1,idx2,s1,s2); //Delete
        int val3=1+solve(idx1+1,idx2+1,s1,s2); //Replace

        ans=min(val1,min(val2,val3));
    }
    return dp[idx1][idx2]=ans;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s1,s2;
    cin>>s1>>s2;
    n=s1.size();
    m=s2.size();

    mem(dp,-1);

    int x=solve(0,0,s1,s2);
    cout<<x<<endl;

    return 0;
}

---------------------------------------------------------------------------------
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

int dp[1005][1005];

int n,m;

int solve(int idx1,int idx2,string &s1, string &s2)
{
    if(idx1<0)
    {
        return idx2+1;// inset
    }
    if(idx2<0)
    {
        return idx1+1; //Delete;
    }

    if(dp[idx1][idx2]!=-1)
    {
        return dp[idx1][idx2];
    }
    int ans=0;
    if(s1[idx1]==s2[idx2])
    {
        ans=solve(idx1-1,idx2-1,s1,s2);
    }
    else
    {
        int val1=1+solve(idx1,idx2-1,s1,s2); //Insert
        int val2=1+solve(idx1-1,idx2,s1,s2); //Delete
        int val3=1+solve(idx1-1,idx2-1,s1,s2); //Replace

        ans=min(val1,min(val2,val3));
    }
    return dp[idx1][idx2]=ans;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s1,s2;
    cin>>s1>>s2;
    n=s1.size();
    m=s2.size();

    mem(dp,-1);

    int x=solve(n-1,m-1,s1,s2);
    cout<<x<<endl;

    return 0;
}

//https://www.codingninjas.com/codestudio/problems/edit-distance_630420?leftPanelTab=0
//https://leetcode.com/problems/edit-distance/description/


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
const int MOD = 1e9+7;
const int inf = 2000000000;
const ll infLL = 9000000000000000;
const ld eps=1e-6 ;// 5 decimal point same

int dp[305][305];


int solve(int idx1,int idx2, string &s1, string &s2)
{
    if(idx1<0 || idx2<0)
    {
        return 0;
    }
    if(dp[idx1][idx2]!=-1)
    {
        return dp[idx1][idx2];
    }

    if(s1[idx1]==s2[idx2])
    {
        dp[idx1][idx2]= 1+solve(idx1-1,idx2-1,s1,s2);
        return dp[idx1][idx2] ;
    }

    dp[idx1][idx2]=max(solve(idx1-1,idx2,s1,s2),solve(idx1,idx2-1,s1,s2));
    return dp[idx1][idx2];
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int t;
    cin>>t;
    while(t--)
    {
        string s1, s2;
        cin>>s1>>s2;
        int n=s1.size();
        int m=s2.size();

        mem(dp,-1);

        int ans=solve(n-1,m-1,s1,s2);
        cout<<ans<<endl;
    }


    return 0;
}
-------------------------------------------------------------------------------
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

int dp[305][305];
int n,m;

int solve(int idx1,int idx2, string &s1, string &s2)
{
    if(idx1==n || idx2==m)
    {
        return 0;
    }
    if(dp[idx1][idx2]!=-1)
    {
        return dp[idx1][idx2];
    }
    int ans=0;
    if(s1[idx1]==s2[idx2])
    {
       ans= 1+solve(idx1+1,idx2+1,s1,s2);
    }
    else
    {
        int val1=solve(idx1+1,idx2,s1,s2);
        int val2=solve(idx1,idx2+1,s1,s2);
        ans=max(val1,val2);
    }

    dp[idx1][idx2]=ans;
    return dp[idx1][idx2];
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int t;
    cin>>t;
    while(t--)
    {
        string s1, s2;
        cin>>s1>>s2;
        n=s1.size();
        m=s2.size();

        mem(dp,-1);

        int ans=solve(0,0,s1,s2);
        cout<<ans<<endl;
 
    }


    return 0;
}

-------------------------------------------------------------------------------------
                   **Iterative DP
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int t;
    cin>>t;
    while(t--)
    {
        string s1, s2;
        cin>>s1>>s2;
        n=s1.size();
        m=s2.size();

        mem(dp,-1);

        for(int j=0;j<=m;j++)
        {
            dp[0][j]=0;
        }
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=0;
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                   dp[i][j]= 1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }

            }
        }

        cout<<dp[n][m]<<endl;

    }


    return 0;
}



//https://www.codingninjas.com/codestudio/problems/longest-common-subsequence_1063255?leftPanelTab=0
//https://www.codingninjas.com/codestudio/problems/longest-common-subsequence_624879
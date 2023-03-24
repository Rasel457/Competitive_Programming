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
string s="";

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
        ans=1+solve(idx1+1,idx2+1,s1,s2);
    }
    else
    {
        int val1=solve(idx1+1,idx2,s1,s2);
        int val2=solve(idx1,idx2+1,s1,s2);
        ans=max(val1,val2);

    }
    return dp[idx1][idx2]=ans;
}

/*void print(int idx1,int idx2, string &s1, string &s2)
{
    if(idx1==n || idx2==m)
    {
        cout<<s<<endl;
        return;
    }

    if(s1[idx1]==s2[idx2])
    {
       s+=s1[idx1];
       print(idx1+1,idx2+1,s1,s2);

    }
    else
    {
        int val1=solve(idx1+1,idx2,s1,s2);
        int val2=solve(idx1,idx2+1,s1,s2);
        if(val1==dp[idx1][idx2])
        {
            print(idx1+1,idx2,s1,s2);
        }
        else
        {
            print(idx1,idx2+1,s1,s2);
        }

    }

}*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int t;
    cin>>t;
    while(t--)
    {
        string s1,s2;
        cin>>s1;
        s2=s1;
        reverse(s2.begin(),s2.end());
        n=s1.size();
        m=s2.size();

        mem(dp,-1);

        int x=solve(0,0,s1,s2);
        //print(0,0,s1,s2);

        cout<<s1.size()-x<<endl;

    }




    return 0;
}


//https://www.codingninjas.com/codestudio/problems/minimum-insertions-to-make-palindrome_985293?leftPanelTab=0
//https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/
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

int r,c;

int dp[55][55][55];

int grid[55][55];

int solve(int i,int j1,int j2)
{
    if(j1<0 || j2<0 || j1>=c ||j2>=c)
    {
        return -1e9;
    }

    if(i==r-1)
    {
        if(j1==j2)
        {
            return grid[i][j1];
        }
        else
        {
             return grid[i][j1]+grid[i][j2];
        }
    }
    if(dp[i][j1][j2]!=-1)
    {
        return dp[i][j1][j2];
    }

    int maxi=-1e9;
    //Exploe all paths of alice and bobs simultaniously
    for(int dj1=-1 ;dj1<=1;dj1++)//alice's move
    {
        for(int dj2=-1 ;dj2<=1;dj2++)//bob's move
        {
            int value=0;
            if(j1==j2)
            {
                value=grid[i][j1];
            }
            else
            {
                value=grid[i][j1]+grid[i][j2];
            }
            value+=solve(i+1,j1+dj1,j2+dj2);
            maxi=max(maxi,value);

        }
    }
    return dp[i][j1][j2]=maxi;
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
        cin>>r>>c;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                cin>>grid[i][j];
            }
        }

        mem(dp,-1);

        cout<<solve(0,0,c-1)<<endl;

    }




    return 0;
}


//https://www.codingninjas.com/codestudio/problems/ninja-and-his-friends_3125885?leftPanelTab=0




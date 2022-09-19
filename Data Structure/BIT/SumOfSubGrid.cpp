#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define endl '\n'
#define pii pair<int,int>
#define pll pair<long long, long long>
#define ff first
#define ss second
#define pb push_back
#define PI 2.0 * acos(0.0)
#define mem(a, b) memset(a, b, sizeof(a))

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
///   *Set.find_by_order(k)  returns a pointer to the k'th element (0 indexed)
///   Set.order_of_key(k)   returns an integer equal to the number of elements STRICTLY SMALLER than 'k'
template<typename T> using orderSet = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;


ll gcd(ll a, ll b) {return __gcd(a,b);}
ll lcm(ll a, ll b) {return a*(b/gcd(a,b));}

const int N = 1e3+10;
const int MOD = 1e9+7;

ll arr[N];
ll sum[N][N];
char grid[N][N];

ll GetAns(int a, int b, int c, int d)
{
    ll ans=0;
    ans=sum[c][d]-sum[a-1][d]-sum[c][b-1]+sum[a-1][b-1];
    return ans;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,q;
    cin>>n>>q;
    char ch;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>ch;
            if(ch=='*')
            {
                grid[i][j]=1;
            }
            else{
                grid[i][j]=0;
            }

        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            sum[i][j]+=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+grid[i][j];
        }
    }

    /*for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {

            cout<<sum[i][j]<<" ";
        }
        cout<<endl;
    }*/

    int y1,y2,x1,x2;

    while(q--)
    {
        cin>>y1>>y2>>x1>>x2;
        ll res=GetAns(y1,y2,x1,x2);
        cout<<res<<endl;

    }



    return 0;

}

// https://cses.fi/problemset/task/1652/
// https://vjudge.net/contest/512497#problem/D



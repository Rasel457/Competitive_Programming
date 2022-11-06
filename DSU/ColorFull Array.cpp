#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define endl '\n'
#define vi vector<int>
#define vl vector<ll>
#define vd vector<ld>
#define pii pair<int,int>
#define pll pair<ll, ll>
#define vii vector<pii>
#define vll vector<pll>
#define ff first
#define ss second
#define pb push_back
#define mem(a, b) memset(a, b, sizeof(a))

const int N = 2e5+10;
const int MOD = 1e9+7;
const int maxn = 105;
const int inf = 2000000000;
const ll infLL = 90000000000000000;

//U,D,L,R
char dir[4]={'U','D','L','R'};
int dx[]={-1, 1, 0, 0, -1, -1, 1, 1};
int dy[]={0, 0, -1, 1, -1, 1, -1, 1};

int kx[]={1, 1, 2, 2, -1, -1, -2, -2};
int ky[]={2, -2, 1, -1, 2, -2, 1, -1};

ll parent[N];
ll color[N];
ll sz[N];

ll l[N];
ll r[N];
ll c[N];
 

void makeSet(ll n)
{
    for(int i=1;i<=n+1;i++)
    {
        parent[i]=i;
        color[i]=0;
        sz[i]=1;
    }
}

ll Find(ll a)
{
    if(a==parent[a])
    {
        return a;
    }
    return parent[a]=Find(parent[a]);
}

void Union(int a, int b)
{
    a=Find(a);
    b=Find(b);
    if(a!=b)
    {
        if(sz[a]<sz[b])
        {
            swap(a,b);
        }
        parent[a]=b;
        sz[a]+=sz[b];
    }
}






int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n,q;
    cin>>n>>q;

    makeSet(n);

    
    for(int i=1;i<=q;i++)
    {
        cin>>l[i]>>r[i]>>c[i];
    }
    ll x;
    for(int i=q;i>=1;i--)
    {
        x=Find(l[i]);

        while(x<=r[i])
        {
            color[x]=c[i];
            Union(x,x+1);
            x=Find(x);

        }
    }

    for(int i=1;i<=n;i++)
    {
        cout<<color[i]<<endl;
    }






    return 0;
}
//https://vjudge.net/contest/522505#problem/Z









#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define endl '\n'
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int,int>
#define pll pair<ll, ll>
#define vii vector<pii>
#define vll vector<pll>
#define ff first
#define ss second
#define pb push_back
#define mem(a, b) memset(a, b, sizeof(a))

const int N = 3e3+5;
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



struct Edge
{
    int u,v,w;
};


vector<Edge>E;
ll dist[N];
int parent[N];
int n,m;


vi bellmanFord(int s)
{
    for(int i=0;i<=n;i++)
    {
        dist[i]=infLL;
    }

    dist[s]=0;
    int x=-1;
    for(int i=1;i<n;i++)
    {
        for(auto e:E)
        {
            if(dist[e.v]>dist[e.u]+e.w)
            {
                dist[e.v]=dist[e.u]+e.w;
                parent[e.v]=e.u;
            }
        }
    }

    for(int i=1;i<=1;i++)
    {
        for(auto e:E)
        {
            if(dist[e.v]>dist[e.u]+e.w)
            {
                dist[e.v]=dist[e.u]+e.w;
                parent[e.v]=e.u;
                x=e.v;
            }
        }
    }
    vi path;
    if(x==-1)
    {
        return path;
    }

    for(int i=1;i<=n;i++)
    {
        x=parent[x];
    }

    int y=x;
    while(y!=x || path.size()==0)
    {
        path.pb(y);
        y=parent[y];
    }
    path.pb(x);
    return path;


}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;
    int x,y,z;
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y>>z;
        E.pb({x,y,z});
    }
    vi cycle=bellmanFord(1);

    if(cycle.size()==0)
    {
         cout<<"NO"<<endl;
    }
    else
    {
        cout<<"YES"<<endl;
        for(int i=cycle.size()-1;i>=0;i--)
        {
            cout<<cycle[i]<<" ";
        }
        cout<<endl;
    }



    return 0;
}
/*
5 10
1 2 6
1 4 7
2 4 8
2 3 5
2 5 -4
3 2 -2
4 3 -3
4 5 9
5 1 2
5 3 7

https://cses.fi/problemset/task/1197/
*/









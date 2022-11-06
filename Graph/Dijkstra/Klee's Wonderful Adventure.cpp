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

const int N = 3e3+10;
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
    ll v;
    ld w;
};

struct Node
{
    ll node;
    ld cost;
    Node(ll _node,ld _cost)
    {
        node=_node;
        cost=_cost;
    }
};
bool operator<(Node A,Node B)
{
    return A.cost>B.cost;
}

vector<Edge>adj[N];
priority_queue<Node>PQ;
ld dist[N];
ll n;

int check(ll x,ll y)
{
    if(x>=1 && y>=1) return 1;
    else if(x<=-1&& y>=1) return 2;
    else if(x<=-1 && y<=-1) return 3;
    else if(x>=1 && y<=-1) return 4;
    else return 5;
}

void dijkstra(ll s)
{
    for(int i=0;i<=n;i++)
    {
        dist[i]=inf;
    }

    PQ.push(Node(s,0.0));
    dist[s]=0.0;

    while(!PQ.empty())
    {
        Node u=PQ.top();
        PQ.pop();

        if(u.cost>dist[u.node])
        {
            continue;
        }

        for(Edge e:adj[u.node])
        {
            if(dist[e.v]>u.cost+e.w)
            {
                dist[e.v]=u.cost+e.w;
                PQ.push(Node(e.v,dist[e.v]));
            }
        }
    }
}





int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    ll speed[6];
    for(int i=1;i<=5;i++)
    {
        cin>>speed[i];
    }
    ll s,d;
    cin>>s>>d;
    ll x,y;
    vector<pair<ld,ld>>p;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>y;
        p.pb({x,y});
    }
    ll x1,y1,x2,y2;
    ld dt,t;
    int a;
    for(int i=0;i<p.size()-1;i++)
    {
        for(int j=i+1;j<p.size();j++)
        {
            x1=p[i].ff;
            y1=p[i].ss;
            x2=p[j].ff;
            y2=p[j].ss;
            dt=sqrt(((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1)));
            if(check(x1,y1)==check(x2,y2))
            {
                a=check(x1,y1);
                t=dt/speed[a];
                adj[i+1].pb({j+1,t});
                adj[j+1].pb({i+1,t});
            }
            else
            {
                t=dt/speed[5];
                adj[i+1].pb({j+1,t});
                adj[j+1].pb({i+1,t});
            }

        }
    }

    dijkstra(s);
    cout<<fixed<<setprecision(10)<<dist[d]<<endl;





    return 0;
}

// https://vjudge.net/contest/522505#problem/AC







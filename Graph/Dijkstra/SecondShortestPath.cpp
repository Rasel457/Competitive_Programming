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

const int N = 5e3+5;
const int MOD = 1e9+7;
const int maxn = 105;
const int inf = 2000000000;
const ll infLL = 9000000000000000000;

//U,D,L,R
char dir[4]={'U','D','L','R'};
int dx[]={-1, 1, 0, 0, -1, -1, 1, 1};
int dy[]={0, 0, -1, 1, -1, 1, -1, 1};

int kx[]={1, 1, 2, 2, -1, -1, -2, -2};
int ky[]={2, -2, 1, -1, 2, -2, 1, -1};


struct Edge
{
    int v;
    int w;
};
struct Edge1
{
    int u,v,w;
};

struct Node
{
    int node,cost;
    Node(int _node,int _cost)
    {
        node=_node;
        cost=_cost;
    }
};

bool operator<(Node A, Node B)
{
    return A.cost>B.cost;
}

vector<Edge>adj[N];
vector<Edge1>E;
priority_queue<Node>PQ;
ll dist[N];
ll dist1[N];
int n,m;

void clr()
{
    for(int i=0;i<=N;i++)
    {
        adj[i].clear();
        dist[i]=0;
        dist1[i]=0;
    }
    E.clear();
}


void dijkstra(int s)
{
    for(int i=0;i<=n;i++)
    {
        dist[i]=infLL;
    }
    PQ.push(Node(s,0));
    dist[s]=0;

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

void dijkstra1(int s)
{
    for(int i=0;i<=n;i++)
    {
        dist1[i]=infLL;
    }
    PQ.push(Node(s,0));
    dist1[s]=0;

    while(!PQ.empty())
    {
        Node u=PQ.top();
        PQ.pop();

        if(u.cost>dist1[u.node])
        {
            continue;
        }

        for(Edge e:adj[u.node])
        {
            if(dist1[e.v]>u.cost+e.w)
            {
                dist1[e.v]=u.cost+e.w;
                PQ.push(Node(e.v,dist1[e.v]));
            }
        }
    }


}




int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t,cas=0;
    cin>>t;

    while(t--)
    {
        clr();
        cas++;
        cin>>n>>m;
        int u,v,w;
        for(int i=1;i<=m;i++)
        {
            cin>>u>>v>>w;
            adj[u].pb({v,w});
            adj[v].pb({u,w});
            E.pb({u,v,w});
        }
        dijkstra(1);
        dijkstra1(n);

        /*for(int i=1;i<=n;i++)
        {
            cout<<dist1[i]<<" ";
        }
        cout<<endl;

        for(int i=n;i>=1;i--)
        {
            cout<<dist1[i]<<" ";
        }*/
        int a,b,c;
        ll mn=infLL;
        for(auto Ed:E)
        {
            a=Ed.u;
            b=Ed.v;
            c=Ed.w;

            if(dist[a]+dist1[b]+c>=dist[n])
            {
                if(dist[a]+dist1[b]+c==dist[n])
                {
                    mn=min(mn,(dist[a]+dist1[b]+(3*c)));
                }
                else
                {
                     mn=min(mn,(dist[a]+dist1[b]+c));
                }

            }

            if(dist[b]+dist1[a]+c>=dist[n])
            {
                if(dist[b]+dist1[a]+c==dist[n])
                {
                    mn=min(mn,(dist[b]+dist1[a]+(3*c)));
                }
                else
                {
                     mn=min(mn,(dist[b]+dist1[a]+c));
                }

            }
        }
        cout<<"Case "<<cas<<": "<<mn<<endl;

    }

    return 0;
}
// https://vjudge.net/problem/LightOJ-1099







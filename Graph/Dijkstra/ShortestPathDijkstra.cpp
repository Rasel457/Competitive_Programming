#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define endl '\n'

const int N = 1e4+5;
const int MOD = 1e9+7;
const int maxn = 205;
const int INF=1000000000;

int dx[]={-1, 1, 0, 0, -1, -1, 1, 1};
int dy[]={0, 0, -1, 1, -1, 1, -1, 1};

int kx[]={1, 1, 2, 2, -1, -1, -2, -2};
int ky[]={2, -2, 1, -1, 2, -2, 1, -1};

int n,e;

struct Edge
{
    int v,w;
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
priority_queue<Node>PQ;
int dist[N];
int parent[N];


void dijkstra(int s,int d)
{
    for(int i=1;i<=n;i++)
    {
        dist[i]=INF;
    }
    dist[s]=0;
    PQ.push(Node(s,0));
    parent[s]=s;

    while(!PQ.empty())
    {
        Node u=PQ.top();
        PQ.pop();

        if(u.cost != dist[u.node])
        {
            continue;
        }
        for(Edge e:adj[u.node])
        {
            if(dist[e.v]>u.cost+e.w)
            {
                dist[e.v]=u.cost+e.w;
                parent[e.v]=u.node;
                PQ.push(Node(e.v,dist[e.v]));
            }
        }
    }
    if(dist[d]==INF)
    {
        cout<<"No route"<<endl;

    }
    else
    {
        vector<int>path;
        path.push_back(d);

        int CurNode=d;
        while(CurNode != s)
        {
            CurNode=parent[CurNode];
            path.push_back(CurNode);

        }
        reverse(path.begin(),path.end());
        cout<<path[0];
        for(int i=1;i<path.size();i++)
        {
            cout<<" -> "<<path[i];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);



    cin>>n>>e;
    for(int i=1;i<=e;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }
    int s,d;
    cin>>s>>d;

    dijkstra(s,d);

    return 0;
}
/*
5 12
0 1 3
0 2 2
1 0 3
1 2 5
1 3 3
2 0 2
2 1 5
2 4 20
3 1 3
3 4 4
4 2 20
4 3 4
0 4
*/

// https://www.hackerearth.com/problem/algorithm/dijkstras/
// https://codeforces.com/contest/20/problem/C


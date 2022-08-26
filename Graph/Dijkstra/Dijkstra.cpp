#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define endl '\n'

const int N = 1e3+5;
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
    int v;
    int w;
};

struct Node
{
    int node,cost;
    Node(int _node, int _cost)
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
int dist[N];


void dijkstra(int s)//1
{
    for(int i=1;i<=n;i++)
    {
        dist[i]=INF;
    }

    dist[s]=0;//dist[1]=0
    PQ.push(Node(s,0));//{1,0}

    while(!PQ.empty())
    {
        Node u=PQ.top();// {1,0}->{3,1}->{2,2}->{4,3}->{5,5}
        PQ.pop();

        if(u.cost != dist[u.node]) //0=0, 1==1, 2==2,3==3,5==5
        {
            continue;
        }

        for(Edge e: adj[u.node])//{3,1},{3,1},{5,2},{3,5}
        {
            if(dist[e.v]>u.cost+e.w)
            {
                dist[e.v]=u.cost+e.w; //dist[3]=1,dist[2]=2,dist[4]=3,dist[5]=5
                PQ.push(Node(e.v,dist[e.v]));//{3,1},{2,2},{4,3},{5,5}
            }
        }

    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin>>n>>e;
    int u,v,w;
    for(int i=1;i<=e;i++)
    {
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }
    int source;
    cin>>source;

    dijkstra(source);
    for(int i=1;i<=n;i++)
    {
        cout<<"Node "<<i<<" Distance: ";
        if(dist[i]==INF)
        {
            cout<<"NOT VISITED"<<endl;
        }
        else
        {
            cout<<dist[i]<<endl;
        }
    }

    return 0;
}
/*
5 6
1 2 2
1 3 1
1 4 3
2 3 1
4 5 2
5 3 5
1
*/

// https://vjudge.net/problem/UVA-1112
// https://www.spoj.com/problems/EZDIJKST/

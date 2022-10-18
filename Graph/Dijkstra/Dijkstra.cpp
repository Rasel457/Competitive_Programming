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

const int N = 1e5+5;
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

struct Edge{
    ll v;
    ll w;
};

struct Node
{
    ll node,cost;

    Node(ll _node,ll _cost)
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
ll dist[N];

ll n,m;


void dijkstra(ll s)//1
{
    for(ll i=1;i<=n;i++)
    {
        dist[i]=infLL;
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

        for(Edge e: adj[u.node])//1,3,2,4,5
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


    cin>>n>>m;
    ll u,v,w;
    for(ll i=1;i<=m;i++)
    {
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }
    int source;
    cin>>source;

    dijkstra(source);
    for(ll i=1;i<=n;i++)
    {
        cout<<"Node "<<i<<" Distance: ";
        if(dist[i]==infLL)
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
// https://cses.fi/problemset/task/1671/

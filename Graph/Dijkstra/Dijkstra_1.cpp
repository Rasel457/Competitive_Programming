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

vii adj[N];
ll dist[N];

void dijkstra ( int s, int n )
{
    for ( int i = 0; i <= n; i++ )
    {
        dist[i] = infLL; /// initilization
    }
    dist[s] = 0; /// initilizing source distance
    priority_queue < pll, vll, greater<pll> > pq;
    pq.push ( { 0, s } ); /// pushing source in queue

    while ( !pq.empty() ) {
        int u = pq.top().ss;
        ll curD = pq.top().ff;
        pq.pop();

        if ( dist[u] < curD ) continue; // important

        for ( auto p : adj[u] ) {
            int v = p.ff;
            ll w = p.ss;
            if ( curD + w < dist[v] ) { // relax operation
                dist[v] = curD + w;
                pq.push ( { dist[v], v } );
            }
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int n, m;
    cin >> n >> m;
    for ( int i = 1; i <= m; i++ )
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb ( { v, w } );
        adj[v].pb ( { u, w } );
    }

    dijkstra ( 1, n-1 );

    for ( int i =0; i <n; i++ )
    {
        cout <<"Distance of node "<<i<<" = "<<dist[i]<<endl;;
    }


    return 0;
}

/*
5 7
1 3 3
1 2 2
1 4 6
2 0 6
2 3 7
0 4 3
3 4 5
*/


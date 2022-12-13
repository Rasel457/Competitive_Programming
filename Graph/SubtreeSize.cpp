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

const int N = 1e4+10;
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

vector<int>adj[N];
int subtree[N];
int visited[N];


void Subtree(int node)
{
    visited[node]=1;

   for(auto v:adj[node])
    {
        if(visited[v]==0)
        {
            Subtree(v);
            subtree[node]+=subtree[v];
        }


    }


}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        subtree[i]=1;
    }
    int x,y;
    for(int i=1;i<=n-1;i++)
    {
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    Subtree(1);
    for(int i=1;i<=n;i++)
    {
        cout<<subtree[i]<<" ";
    }


    return 0;
}

/*

11
1 2
1 9
2 3
2 5
2 8
9 10
9 11
3 4
5 6
5 7
*/











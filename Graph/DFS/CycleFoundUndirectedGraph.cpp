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

const int N = 1e7+10;
const int MOD = 1e9+7;
const int maxn = 105;
const int inf = 2000000000;
const ll infLL = 90000000000000000;

//U,D,L,R
char dir[4]={'U','D','L','R'};
ll dx[]={-1, 1, 0, 0, -1, -1, 1, 1};
ll dy[]={0, 0, -1, 1, -1, 1, -1, 1};

int kx[]={1, 1, 2, 2, -1, -1, -2, -2};
int ky[]={2, -2, 1, -1, 2, -2, 1, -1};

vector<int>adj[100];
int visited[100];
int parent[100];

bool flag=false;

void dfs(int u,int p)
{
    if(flag==true)
    {
        return;
    }
    visited[u]=1;
    parent[u]=p;

    for(auto v:adj[u])
    {
        if(visited[v]==0)
        {
            dfs(v,u);
        }
        if(visited[v]==1 && parent[u]==v)
        {
           continue;
        }
        if(visited[v]==1 && parent[u]!=v)
        {
            flag=true;
            return;
        }
    }
    visited[u]=2;

}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int node,edge;
    cin>>node>>edge;

    int x,y;
    for(int i=1;i<=edge;i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int s;
    cin>>s;
    dfs(s,1);

    if(flag==true)
    {
        cout<<"Cycle Found"<<endl;
    }
    else
    {
        cout<<"All Nodes Are Visited"<<endl;
    }



    return 0;
}

/*
5 5
1 2
2 3
2 4
3 4
4 5
1

5 4
1 2
2 3
2 4
4 5
1
*/


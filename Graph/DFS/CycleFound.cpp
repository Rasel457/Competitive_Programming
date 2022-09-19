#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define endl '\n'
#define pii pair<int,int>
#define pll pair<long long, long long>
#define ff first
#define ss second
#define pb push_back
#define mem(a, b) memset(a, b, sizeof(a))

const int N = 1e4+5;
const int MOD = 1e9+7;
const int maxn = 1005;
const int INF=1e8;

//U,D,L,R
char dir[4]={'U','D','L','R'};
int dx[]={-1, 1, 0, 0, -1, -1, 1, 1};
int dy[]={0, 0, -1, 1, -1, 1, -1, 1};

int kx[]={1, 1, 2, 2, -1, -1, -2, -2};
int ky[]={2, -2, 1, -1, 2, -2, 1, -1};

vector<int>adj[100];
int visited[100];

bool flag=false;

void dfs(int u)
{
    if(flag==true)
    {
        return;
    }
    visited[u]=1;

    for(auto v:adj[u])
    {
        if(visited[v]==0)
        {
            dfs(v);
        }
        if(visited[v]==1)
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
        //adj[y].push_back(x);
    }
    int s;
    cin>>s;
    dfs(s);

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
6 6
1 2
1 4
2 3
3 6
6 5
5 2
1
*/

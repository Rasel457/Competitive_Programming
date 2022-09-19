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

const int N = 1e5+5;
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
vector<int>sorted;
int visited[100];
bool flag=false;

void dfs(int u)
{
    if(flag==true)
    {
     	return;
    }
    visited[u]=1;
    for(int i=0;i<adj[u].size();i++)
    {
        int v=adj[u][i];
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
    sorted.push_back(u); // All child explored
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int nodes,edges;
    cin>>nodes>>edges;

    int x,y;
    for(int i=1;i<=edges;i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);

    }

    for(int i=1;i<=nodes;i++)
    {
        if(visited[i]==0)
        {
            dfs(i);
        }
    }

    if(flag==true)
    {
        cout<<"Cycle Found"<<endl;
    }
    else
    {
	reverse(sorted.begin(),sorted.end());
        cout<<"Topological Sort : ";
        for(int i=0;i<sorted.size();i++)
        {
            cout<<sorted[i]<<" ";
        }
        cout<<endl;
    }


    return 0;
}

/*

5 4
1 2
3 2
2 4
2 5

https://iq.opengenus.org/topological-sort-bfs/
6 10
1 2
1 4
2 3
2 4
3 4
3 5
3 6
4 5
4 6
5 6

8 8
1 2
2 3
3 4
4 5
5 6
6 7
7 5
8 3

*/

// https://www.spoj.com/problems/TOPOSORT/


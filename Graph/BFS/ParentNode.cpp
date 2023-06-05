#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define endl '\n'

const int N = 5e5+5;
const int MOD = 1e9+7;

vector<int>adj[100];
int visited[100];
int parent[100];

void bfs(int source)
{

    queue<int>Q;
    Q.push(source);
    visited[source]=1;
    parent[source]=source;

    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();

        for(int i=0;i<adj[u].size();i++)
        {
            int v=adj[u][i];
            if(visited[v]==0)
            {
                visited[v]=1;
                parent[v]=u;
                Q.push(v);
            }
        }
    }
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
   /* int s;
    cin>>s;
    bfs(s);*/

    for(int i=0;i<=node;i++)
    {
        if(visited[i]==0)
        {
            bfs(i);
        }
    }

    for(int i=1;i<=node;i++)
    {
        cout<<"Parent of "<<i<<": "<<parent[i]<<endl;
    }



    return 0;
}

/*
Multiple component
9 8
6 4
4 3
4 5
3 2
5 2
5 1
2 1
8 9
*/

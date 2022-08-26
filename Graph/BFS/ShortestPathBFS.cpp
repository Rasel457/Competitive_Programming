#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define endl '\n'

const int N = 5e5+5;
const int MOD = 1e9+7;

vector<int>adj[100];
int visited[100];
int dist[100];
int parent[100];


void bfs(int source, int destination)
{

    queue<int>Q;
    Q.push(source);
    visited[source]=1;
    dist[source]=0;
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
               // dist[v]=dist[u]+1;
                parent[v]=u;
                Q.push(v);
            }
        }
    }

    if(visited[destination]==0)
    {
        cout<<"Not Path"<<endl;
    }
    else
    {
        vector<int>path;
        path.push_back(destination);

        int CurNode=destination;
        while(CurNode != source)
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
        path.clear();
        cout<<endl;

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

    //int s,d;
    //cin>>s>>d;
    //bfs(s,d);
    for(int i=0;i<=node;i++)
    {
        memset(visited, 0, sizeof(visited));
        memset(parent, 0, sizeof(parent));
        if(visited[i]==0 && !adj[i].empty())
        {
            bfs(i,5);
        }
    }



    return 0;
}

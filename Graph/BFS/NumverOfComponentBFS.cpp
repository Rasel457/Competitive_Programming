#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define endl '\n'

const int N = 5e5+5;
const int MOD = 1e9+7;

vector<int>adj[100];
int visited[100];

void bfs(int source)
{

    queue<int>Q;
    Q.push(source);
    visited[source]=1;

    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();

        for(int i=0;i<adj[u].size();i++)
        {
            if(visited[adj[u][i]]==0)
            {
                int v=adj[u][i];
                visited[v]=1;
                Q.push(v);
            }
        }
    }
    //cout<<"All adjacent Nodes are visited"<<endl;
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
    int cnt=0;
    for(int i=1;i<=node;i++)
    {
        if(visited[i]==0)
        {
            bfs(i);
            cnt++;
        }
    }
    cout<<"Number of component : "<<cnt<<endl;


    return 0;
}

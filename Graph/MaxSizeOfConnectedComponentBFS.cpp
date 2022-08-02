#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define endl '\n'

const int N = 5e5+5;
const int MOD = 1e9+7;

vector<int>adj[100];
int visited[100];
int cnt=0;
void bfs(int source)
{

    queue<int>Q;
    Q.push(source);
    visited[source]=1;
    cnt++;

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
                Q.push(v);
                cnt++;
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
    int ans=0;
    for(int i=0;i<=node;i++)
    {
        if(visited[i]==0)
        {
            cnt=0;
            bfs(i);
            ans=max(ans,cnt);
        }
    }
   cout<<ans<<endl;


    return 0;
}

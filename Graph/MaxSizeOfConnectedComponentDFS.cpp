#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define endl '\n'

const int N = 5e5+5;
const int MOD = 1e9+7;

vector<int>adj[N];
int visited[N];

int cnt=0;
void dfs(int u)
{

    visited[u]=1;
    cnt++;

    for(auto v:adj[u])
    {
        if(visited[v]==0)
        {
             dfs(v);
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

    int ans=0;
    for(int i=1;i<=node;i++)
    {
        if(visited[i]==0)
        {
            cnt=0;
            dfs(i);
            ans=max(ans,cnt);
        }
    }
    cout<<ans<<endl;


    return 0;
}


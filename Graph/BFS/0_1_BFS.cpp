#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define endl '\n'

const int N = 5e5+5;
const int MOD = 1e9+7;
const int maxn = 205;

int dx[]={-1, 1, 0, 0, -1, -1, 1, 1};
int dy[]={0, 0, -1, 1, -1, 1, -1, 1};

int kx[]={1, 1, 2, 2, -1, -1, -2, -2};
int ky[]={2, -2, 1, -1, 2, -2, 1, -1};

vector<int>adj[300];
vector<int>weight[300];
int visited[300];
int dist[300];


void bfs(int source)
{
    deque<int>Q;
    Q.push_back(source);
    visited[source]=1;
    dist[source]=0;

    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop_front();

        for(int i=0;i<adj[u].size();i++)
        {
            int v=adj[u][i];
            int w=weight[u][i];
            if(visited[v]==0)
            {
                dist[v]=dist[u]+weight[u][i];
                visited[v]=1;
                if(w==1)
                {
                    Q.push_back(v);
                }
                else
                {
                    Q.push_front(v);
                }

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

    int x,y,w;
    for(int i=1;i<=edge;i++)
    {
        cin>>x>>y>>w;
        adj[x].push_back(y);
        adj[y].push_back(x);
        weight[x].push_back(w);
        weight[y].push_back(w);

    }
    int s;
    cin>>s;
    bfs(s);

    cout<<"Source from "<<s<<endl;
    for(int i=1;i<=node;i++)
    {
        cout<<"Distance of " <<i<<" is: "<<dist[i]<<endl;
    }


    return 0;
}
/*
8 10
1 2 1
1 3 0
1 4 1
2 5 0
2 6 1
3 6 1
3 7 1
4 7 1
7 8 1
6 8 1
1
*/

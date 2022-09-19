#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define endl '\n'

const int N = 5e5+5;
const int MOD = 1e9+7;

vector<int>adj[100];
//bool mark[100];
int visited[100];
int level[100];

void bfs(vector<int>sources)
{
    queue<int>Q;
    int source;
    for(int i=0;i<sources.size();i++)
    {
        source=sources[i];
        Q.push(source);
        visited[source]=1;
        level[source]=0;
    }


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
                level[v]=level[u]+1;
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

    int numberOfSources;
    cin>>numberOfSources;
    vector<int>sources;
    for(int i=1;i<=numberOfSources;i++)
    {
        int source;
        cin>>source;
        //mark[source]=1;
        sources.push_back(source);
    }

    bfs(sources);

    //cout<<"Source from "<<s<<endl;
    for(int i=1;i<=node;i++)
    {
        if(level[i]==0)
        {
            continue;
        }
        cout<<"Distance of " <<i<<" is: "<<level[i]<<endl;
    }


    return 0;
}
/*
10 13
1 2
1 3
2 4
3 4
1 5
5 6
3 6
6 7
5 10
6 10
10 9
7 9
9 8
3
1 7 10
Tanvir sajol
*/

//https://lightoj.com/problem/jane-and-the-frost-giants
// https://vjudge.net/contest/512497#problem/Q

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define endl '\n'

const int N = 5e5+5;
const int MOD = 1e9+7;

map<string,vector<string>>adj;
map<string,string>parent;
map<string,int>visited;



void bfs(string source, string destination)
{

    queue<string>Q;
    Q.push(source);
    visited[source]=1;
    parent[source]=source;

    while(!Q.empty())
    {
        string u=Q.front();
        Q.pop();

        for(int i=0;i<adj[u].size();i++)
        {
            string v=adj[u][i];
            if(visited[v]==0)
            {
                visited[v]=1;
                parent[v]=u;
                Q.push(v);
            }
        }
    }

    if(visited[destination]==0)
    {
        cout<<"No route"<<endl;

    }
    else
    {
        vector<pair<string,string>>path;
        path.push_back({parent[destination],destination});

        string CurNode=destination;
        while(CurNode != source)
        {
            CurNode=parent[CurNode];
            path.push_back({parent[CurNode],CurNode});

        }
        reverse(path.begin(),path.end());

        for(int i=1;i<path.size();i++)
        {
            cout<<path[i].first<<" "<<path[i].second<<endl;
        }
        path.clear();


    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int t=0;
    while(cin>>n)
    {
        if(t>0)
        {
            cout<<endl;
        }

        t++;
        cin.ignore();
        adj.clear();
        visited.clear();
        parent.clear();
        string x,y;
        for(int i=1;i<=n;i++)
        {
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        string s,d;
        cin>>s>>d;
        bfs(s,d);
        
    }


    //int s,d;
    //cin>>s>>d;
    //bfs(s,d);




    return 0;
}

//https://vjudge.net/problem/UVA-762

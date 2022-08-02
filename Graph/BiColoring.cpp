#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define endl '\n'

const int N = 5e5+5;
const int MOD = 1e9+7;

const int Black=0;
const int Blue=1;
const int Unknown=-1;

vector<int>adj[205];
vector<int>color(205,Unknown);
int visited[205];


void clr()
{
    for(int i=0;i<205;i++)
    {
        color[i]=Unknown;
    }
    for(int i=0;i<205;i++)
    {
        adj[i].clear();
    }

}

void bfs(int source)
{

    queue<int>Q;
    Q.push(source);
    color[source]=Black;
    bool flag=true;

    while(!Q.empty() && flag)
    {
        int u=Q.front();
        Q.pop();

        for(int i=0;i<adj[u].size();i++)
        {
            int v=adj[u][i];
            if(color[v]==Unknown)
            {
                color[v]=1-color[u];
                Q.push(v);
            }
            else if(color[v]==color[u])
            {
                flag=false;
                break;
            }
        }
    }
    if(flag==true)
    {
        cout<<"BICOLORABLE."<<endl;
    }
    else
    {
        cout<<"NOT BICOLORABLE."<<endl;
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int node;

    while(cin>>node)
    {
        if(node==0)
        {
            break;
        }
        clr();
        int edge;
        cin>>edge;

        int x,y;
        for(int i=1;i<=edge;i++)
        {
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        bfs(0);
    }

    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define endl '\n'

const int N = 1e4+5;
const int MOD = 1e9+7;
const int maxn = 205;
const int INF=1e8;

int dx[]={-1, 1, 0, 0, -1, -1, 1, 1};
int dy[]={0, 0, -1, 1, -1, 1, -1, 1};

int kx[]={1, 1, 2, 2, -1, -1, -2, -2};
int ky[]={2, -2, 1, -1, 2, -2, 1, -1};

vector<int>adj[100];
int indegree[100];
vector<int>sorted;
int nodes,edges;
bool flag=false;

void topological_sort()
{
    queue<int>Q;
    for(int i=0;i<nodes;i++)
    {
        if(indegree[i]==0)
        {
            Q.push(i);
        }
    }
    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        sorted.push_back(u);

        for(int i=0;i<adj[u].size();i++)
        {
            int v=adj[u][i];
            indegree[v]--;
            if(indegree[v]==0)
            {
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

    cin>>nodes>>edges;

    int x,y;
    for(int i=1;i<=edges;i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        indegree[y]++;
    }
    /*for(int i=0;i<nodes;i++)
    {
        for(int j=0;j<adj[i].size();j++)
        {
            indegree[adj[i][j]]++;
        }
    }
    for(int i=0;i<nodes;i++)
    {
        cout<<i<<" "<<indegree[i]<<endl;
    }*/
    topological_sort();
    for(int i=0;i<nodes;i++)
    {
        if(indegree[i]!=0)
        {
            flag=true;
            break;
        }
    }
    if(flag==true)
    {
        cout<<"Cycle Found"<<endl;
    }
    else
    {
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
0 1
2 1
1 3
1 4
https://iq.opengenus.org/topological-sort-bfs/
6 10
0 1
0 3
1 2
1 3
2 3
2 4
2 5
3 4
3 5
4 5
Geeks for geeks
6 6
5 2
5 0
4 0
4 1
2 3
3 1

8 8
0 1
1 2
1 3
3 4
4 5
5 6
6 5
7 2


*/








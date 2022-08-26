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

int n,e;
struct Edge
{
    int u,v,w;
};

vector<Edge>E;
int dist[N];
int parent[N];
void bellman_ford(int s,int d)
{
    for(int i=1;i<=n;i++)
    {
        dist[i]=INF;
    }
    dist[s]=0;
    parent[s]=s;

    for(int i=1;i<n;i++)
    {
        for(Edge e:E)
        {
            if(dist[e.v]>dist[e.u]+e.w)
            {
                dist[e.v]=dist[e.u]+e.w;
                parent[e.v]=e.u;
            }
        }
    }

    if(dist[d]==INF)
    {
        cout<<"No route"<<endl;

    }
    else
    {
        vector<int>path;
        path.push_back(d);

        int CurNode=d;
        while(CurNode != s)
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
    }

}




int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin>>n>>e;

    int x,y,z;
    for(int i=1;i<=e;i++)
    {
        cin>>x>>y>>z;
        E.push_back({x,y,z});
    }
    int source,des;
    cin>>source>>des;

    bellman_ford(source,des);

    return 0;
}

/*
5 10
1 2 6
1 4 7
2 4 8
2 3 5
2 5 -4
3 2 -2
4 3 -3
4 5 9
5 1 2
5 3 7
1 2

7 10
1 2 6
1 3 5
1 4 5
3 2 -2
4 3 -2
2 5 -1
3 5 1
4 6 -1
5 7 3
6 7 3
1 7

4 4
1 2 4
1 4 5
4 3 3
3 2 -10
1 2


*/





#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define endl '\n'
#define pii pair<int,int>
#define pll pair<long long, long long>
#define ff first
#define ss second
#define pb push_back
#define mem(a, b) memset(a, b, sizeof(a))

const int N = 1e5+5;
const int MOD = 1e9+7;
const int maxn = 105;
const int INF=1e8;

//U,D,L,R
char dir[4]={'U','D','L','R'};
int dx[]={-1, 1, 0, 0, -1, -1, 1, 1};
int dy[]={0, 0, -1, 1, -1, 1, -1, 1};

int kx[]={1, 1, 2, 2, -1, -1, -2, -2};
int ky[]={2, -2, 1, -1, 2, -2, 1, -1};


vector<int>adj1[N];
vector<int>adj2[N];
int visited[N];
stack<int>st;
int n,m;


void topoSort(int u)
{
    visited[u]=1;
    for(int i=0;i<adj1[u].size();i++)
    {
        int v=adj1[u][i];
        if(visited[v]==0)
        {
            topoSort(v);
        }
    }
    st.push(u);
}

void dfs(int u)
{
    if(visited[u]==1)
    {
        return;
    }
    visited[u]=1;
    for(auto v:adj2[u])
    {
        dfs(v);
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin>>n>>m;
    int x,y;
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y;
        adj1[x].pb(y);
        adj2[y].pb(x);
    }

    for(int i=1;i<=n;i++)
    {
        if(visited[i]==0)
        {
            topoSort(i);
        }

    }
    /*while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;*/

    mem(visited,0);
    int cnt=0;
    int s;

    for(int i=1;i<=n;i++)
    {
        s=st.top();
        //cout<<s<<endl;
        st.pop();
        if(visited[s]==0)
        {
            cnt++;
            dfs(s);
        }
    }
    cout<<"Strongly Connected Component: "<<cnt<<endl;


    return 0;
}
/*
7 8
1 2
2 3
3 1
3 4
4 5
5 6
6 7
7 5
*/



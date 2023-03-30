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
const int maxn = 1005;
const int INF=1e8;

//U,D,L,R
char dir[4]={'U','D','L','R'};
int dx[]={-1, 1, 0, 0, -1, -1, 1, 1};
int dy[]={0, 0, -1, 1, -1, 1, -1, 1};

int kx[]={1, 1, 2, 2, -1, -1, -2, -2};
int ky[]={2, -2, 1, -1, 2, -2, 1, -1};


vector<int>adj[1000];
int visited[1000];
stack<int>st;
bool flag=false;
int start_time[1000];
int endtime[1000];
int _time=1;


int node,edge;

bool cmp(pii a,pii b)
{
    return a.second>b.second;
}

void dfs(int u)
{
    visited[u]=1;
    start_time[u]=_time;
    _time++; 
    for(int i=0;i<adj[u].size();i++)
    {
        int v=adj[u][i];
        if(visited[v]==0)
        {
            dfs(v);
        }
        if(visited[v]==1)
        {
           flag=true;
           return;
        }
    }
    visited[u]=2;
    st.push(u);
    endtime[u]=_time;
    _time++;

}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>node>>edge;
    int x,y;
    for(int i=1;i<=edge;i++)
    {
         cin>>x>>y;
         adj[x].push_back(y);
    }

    for(int i=1;i<=node;i++)
    {
        if(visited[i]==0)
        {
            dfs(i);
        }
    }

    if(flag==true)
    {
        cout<<"Cycle Found"<<endl;
    }
    else
    {
         cout<<"Topological Sort using Stack : ";
         while(!st.empty())
         {
             cout<<st.top()<<" ";
             st.pop();
         }
         cout<<endl;

         cout<<"Topological Sort using Endtime : ";
         vector<pii>p;
         for(int i=1;i<=node;i++)
         {
            p.pb({i,endtime[i]});
         }
         sort(p.begin(),p.end(),cmp);
         for(int i=0;i<p.size();i++)
         {
             cout<<p[i].first<<" ";
         }
    }


}

/*
7 9
1 2
2 3
2 4
3 4
3 5
4 6
5 6
5 7
6 7
*/
// https://vjudge.net/problem/UVA-10305
// https://lightoj.com/problem/hit-the-light-switches

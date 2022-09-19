#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define endl '\n'
#define pii pair<int,int>

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

char Graph[maxn][maxn];
bool visited[maxn][maxn],ase=false;
pii parent[maxn][maxn];
int n,m;

string s="";

struct node
{
    int x,y;
};

bool Valid(int x,int y)
{
    return (x>=1 && x<=n && y>=1 && y<=m && !visited[x][y]);
}

void bfs(int sx,int sy)
{

    queue<node>Q;
    Q.push({sx,sy});
    visited[sx][sy]=1;
    parent[sx][sy]={-1,-1};

    while(!Q.empty())
    {
        int p=Q.front().x;
        int q=Q.front().y;
        Q.pop();

        for(int i=0;i<4;i++)
        {
            int next_p=p+dx[i];
            int next_q=q+dy[i];
            if(Valid(next_p,next_q))
            {
                visited[next_p][next_q]=1;
                parent[next_p][next_q]={p,q};
                Q.push({next_p,next_q});
                if(Graph[next_p][next_q]=='B')
                {
                    //cout<<"paisi"<<endl;
                    ase=true;
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


    cin>>n>>m;

    int sx,sy,dx,dy;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>Graph[i][j];
            if(Graph[i][j]=='#')
            {
                visited[i][j]=1;
            }
            if(Graph[i][j]=='A')
            {
                sx=i;
                sy=j;
            }
            if(Graph[i][j]=='B')
            {
                dx=i;
                dy=j;
            }

        }
    }
    bfs(sx,sy);

    //cout<<sx<<" "<<sy<<" "<<dx<<" "<<dy<<endl;

    if(ase==false)
    {
        cout<<"NO"<<endl;
    }
    else
    {
         pii x={dx,dy};
         while(x.first!=-1 && x.second!=-1)
         {
             pii y=parent[x.first][x.second];
             //cout<<y.first<<" "<<y.second<<endl;

             if(y.first-1==x.first && y.second==x.second)
             {
                 s.push_back('U');
             }
             else if(y.first+1==x.first && y.second==x.second)
             {
                 s.push_back('D');
             }
             else if(y.first==x.first && y.second+1==x.second)
             {
                 s.push_back('R');
             }
             else if(y.first==x.first && y.second-1==x.second)
             {
                 s.push_back('L');
             }
             x=y;
         }
         cout<<"YES"<<endl;
         cout<<s.size()<<endl;
         reverse(s.begin(),s.end());
         cout<<s<<endl;

    }

    return 0;
}
---------------------------------------------------------------------------------

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define endl '\n'
#define pii pair<int,int>

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

char Graph[maxn][maxn];
bool visited[maxn][maxn],ase=false;
pii parent[maxn][maxn];
int n,m;

string s="";

struct node
{
    int x,y;
};

bool Valid(int x,int y)
{
    return (x>=1 && x<=n && y>=1 && y<=m && !visited[x][y]);
}

void bfs(int sx,int sy)
{

    queue<node>Q;
    Q.push({sx,sy});
    visited[sx][sy]=1;
    parent[sx][sy]={-1,-1};

    while(!Q.empty())
    {
        int p=Q.front().x;
        int q=Q.front().y;
        Q.pop();

        for(int i=0;i<4;i++)
        {
            int next_p=p+dx[i];
            int next_q=q+dy[i];
            if(Valid(next_p,next_q))
            {
                visited[next_p][next_q]=1;
                parent[next_p][next_q]={p,q};
                Q.push({next_p,next_q});
                if(Graph[next_p][next_q]=='B')
                {
                    //cout<<"paisi"<<endl;
                    ase=true;
                }

            }
        }
    }
}

char path(int x1,int y1,int x2,int y2)
{
    for(int i=0;i<4;i++)
    {
        if(x1+dx[i]==x2 && y1+dy[i]==y2)
        {
            return dir[i];
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin>>n>>m;

    int sx,sy,dx,dy;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>Graph[i][j];
            if(Graph[i][j]=='#')
            {
                visited[i][j]=1;
            }
            if(Graph[i][j]=='A')
            {
                sx=i;
                sy=j;
            }
            if(Graph[i][j]=='B')
            {
                dx=i;
                dy=j;
            }

        }
    }
    bfs(sx,sy);

    //cout<<sx<<" "<<sy<<" "<<dx<<" "<<dy<<endl;

    if(ase==false)
    {
        cout<<"NO"<<endl;
    }
    else
    {
         pii x={dx,dy};
         while(x.first!=-1 && x.second!=-1)
         {
             pii y=parent[x.first][x.second];
             //cout<<y.first<<" "<<y.second<<endl;
             if(y.second==-1)
             {
                 break;
             }

             s.push_back(path(y.first,y.second,x.first,x.second));
             x=y;
         }
         cout<<"YES"<<endl;
         cout<<s.size()<<endl;
         reverse(s.begin(),s.end());
         cout<<s<<endl;

    }

    return 0;
}






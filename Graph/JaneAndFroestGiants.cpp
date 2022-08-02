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

char ch[maxn][maxn];
int visited[maxn][maxn];
int levFire[maxn][maxn];
int levJane[maxn][maxn];

int r,c;
bool Valid(int x,int y)
{
    return(x>=1 && x<=r && y>=1 && y<=c && ch[x][y]!='#' && !visited[x][y]);
}

bool escape(int x,int y)
{
    return(x<1 || x>r || y<1 || y>c);
}

void clr()
{
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
        {
            levFire[i][j]=-1;
            levJane[i][j]=-1;

        }
    }
}
void resetVisited(){
    for (int i = 1; i <= r; i++){
        for (int j = 1; j <= c; j++){
            visited[i][j] = 0;
        }
    }
}

struct node{
    int x;
    int y;
};
void FireMultiSourceBFS(vector<node>fires)
{
    resetVisited();
    queue<node>Q;

    for(auto fire:fires)
    {
        Q.push(fire);
        visited[fire.x][fire.y]=1;
        levFire[fire.x][fire.y]=0;
    }


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
                levFire[next_p][next_q]=levFire[p][q]+1;
                Q.push({next_p,next_q});

            }
        }
    }

}


int JaneBFS(int sx,int sy){
    resetVisited();

    queue<node> Q;

    Q.push({sx,sy});
    visited[sx][sy] = 1;
    levJane[sx][sy] = 0;

    while(!Q.empty()){
        int p=Q.front().x;
        int q=Q.front().y;
        Q.pop();

        for (int i = 0; i < 4; i++){
            int next_p = p+ dx[i];
            int next_q = q+ dy[i];

            if (escape(next_p, next_q)){
                return levJane[p][q] + 1;
            }

            if (Valid(next_p, next_q)){
                if (levFire[next_p][next_q] > levJane[p][q] + 1)
                {
                    levJane[next_p][next_q] = levJane[p][q] + 1;
                    visited[next_p][next_q] = 1;
                    Q.push({next_p, next_q});
                }
            }
        }
    }
    return -1;
}




int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    int cas=0;
    while(t--)
    {
        cas++;
        cin>>r>>c;

        clr();

        vector<node>fires;
        int p,q;

        for(int i=1;i<=r;i++)
        {
            for(int j=1;j<=c;j++)
            {
                cin>>ch[i][j];
                if(ch[i][j]=='J')
                {
                    p=i;
                    q=j;
                }
                else if(ch[i][j]=='F')
                {
                    fires.push_back({i,j});
                }
            }
        }

        FireMultiSourceBFS(fires);
        int ans=JaneBFS(p,q);

        if(ans==-1)
        {
            cout<<"Case "<<cas<<": IMPOSSIBLE"<<endl;

        }
        else{
             cout<<"Case "<<cas<<": "<<ans<<endl;
        }



    }

    return 0;
}

//https://lightoj.com/problem/jane-and-the-frost-giants

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define endl '\n'
#define pii pair<int,int>

const int N = 2e5+5;
const int MOD = 1e9+7;
const int maxn = 1005;
const int INF=1e8;

//U,D,L,R
char dir[4]={'U','D','L','R'};
int dx[]={-1, 1, 0, 0, -1, -1, 1, 1};
int dy[]={0, 0, -1, 1, -1, 1, -1, 1};

int kx[]={1, 1, 2, 2, -1, -1, -2, -2};
int ky[]={2, -2, 1, -1, 2, -2, 1, -1};

vector<int>adj[N];
vector<int>subtree_size(N);

int calc (int node) {
   //cout<<node<<endl;
   if (adj[node].size() == 0) {
      return 1;
   } else {
       for (int i = 0; i < adj[node].size(); i++) {
          //cout<<adj[node][i]<<endl;
          subtree_size[node] += calc(adj[node][i]);
          //cout<<node<<" "<<subtree_size[node]<<endl;
       }
   }
   //cout<<"here"<<endl;
   //cout<<node<<" "<<subtree_size[node]<<endl;
   return subtree_size[node] + 1;

}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;

    int x;
    for(int i=2;i<=n;i++)
    {
        cin>>x;
        adj[x].push_back(i);
    }

    calc(1);

    for(int i=1;i<=n;i++)
    {
        cout<<subtree_size[i]<<" ";
    }


    return 0;
}
/*
7
1 1 2 2 3 3
*/


// https://vjudge.net/contest/512497#problem/N
// https://cses.fi/problemset/task/1674/
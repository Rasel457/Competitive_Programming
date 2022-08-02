#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define endl '\n'

const int N = 5e5+5;
const int MOD = 1e9+7;
const int maxn = 505;

int arr[N];
int parent[N];

void makeSet(int n)
{
    for(int i=1;i<=n;i++)
    {
        parent[i]=-1;
    }

}

int Find(int a)
{
    if(parent[a]<0)return a;
    return parent[a]=Find(parent[a]);
}
void Union(int a, int b)
{
    int p=Find(a);
    int q=Find(b);

    if(p!=q)
    {
        parent[p]+=parent[q];
        parent[q]=p;
    }

}




int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin>>n>>m;
    makeSet(n);
    int u,v;
    while(m--)
    {
        cin>>u>>v;

        Union(u,v);



    }
    ll ans=1;
    for(int i=1;i<=n;i++)
    {
        if(parent[i]<0)
        {
            ans=(ans*abs(parent[i]))%MOD;
        }
    }
    cout<<ans<<endl;


}

//https://www.hackerearth.com/problem/algorithm/teachers-dilemma-3-00955296/
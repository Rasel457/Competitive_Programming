#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define endl '\n'
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int,int>
#define pll pair<ll, ll>
#define vii vector<pii>
#define vll vector<pll>
#define ff first
#define ss second
#define pb push_back
#define mem(a, b) memset(a, b, sizeof(a))

const int N = 1e5+123;
const int MOD = 1e9+7;
const int maxn = 105;
const int inf = 2000000000;
const ll infLL = 90000000000000000;

//U,D,L,R
char dir[4]={'U','D','L','R'};
int dx[]={-1, 1, 0, 0, -1, -1, 1, 1};
int dy[]={0, 0, -1, 1, -1, 1, -1, 1};

int kx[]={1, 1, 2, 2, -1, -1, -2, -2};
int ky[]={2, -2, 1, -1, 2, -2, 1, -1};

int parent[N];
int Size[N];
int n,k;

void makeSet()
{
    for(int i=1;i<=n;i++)
    {
        parent[i]=i;
        Size[i]=1;
    }
}

int Find(int a)
{
    if(a==parent[a])
    {
        return a;
    }
    return parent[a]=Find(parent[a]);
}

void Union(int a,int b)
{
    a=Find(a);
    b=Find(b);
    if(a!=b)
    {
        if(Size[a]<Size[b])
        {
            swap(a,b);
        }
        parent[b]=a;
        Size[a]+=Size[b];
    }
}




int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>k;
    makeSet();

    while(k--)
    {
        int u,v;
        cin>>u>>v;
        Union(u,v);

    }

    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(Find(i)==i)
        {
            cnt++;
        }

    }
    cout<<cnt<<endl;



    return 0;
}
//https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/city-and-flood-1/






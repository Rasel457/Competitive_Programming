#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+20;

int arr[N],tree[4*N];


void build(int node, int L, int R)
{
    if(L==R)
    {
        tree[node]=arr[L];
        return;
    }
    int mid=(L+R)/2;
    build(node*2,L,mid);
    build(node*2+1,mid+1,R);
    tree[node]=tree[node*2]+tree[node*2+1];
    //tree[node]=max(tree[node*2],tree[node*2+1]);

}



void update(int node,int L, int R, int pos, int val)
{
    if(L==R)
    {
        tree[node]+=val;
        return;
    }

    int mid=(L+R)/2;
    if(pos<=mid)
    {
        update(node*2,L,mid,pos,val);
    }
    else
    {
        update(node*2+1,mid+1,R,pos,val);
    }
    tree[node]=tree[node*2]+tree[node*2+1];
}

int query(int node,int L, int R, int l, int r)
{
    if(l>R || r<L)
    {
        return 0;
    }

    if(L>=l && R<=r)
    {
        return tree[node];
    }

    int mid=(L+R)/2;
    int x=query(node*2,L,mid,l,r);
    int y=query(node*2+1,mid+1,R,l,r);
    return x+y;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }

    build(1,1,n);
    cout<<query(1,1,n,2,5)<<endl;
    update(1,1,n,3,2);
    cout<<query(1,1,n,2,5)<<endl;

}

/*
8
2 3 2 5 -1 2 5 3
*/




#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define endl '\n'
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<pii>
#define vll vector<pll>
#define ff first
#define ss second
#define pb push_back
#define PI 2.0 * acos(0.0)
#define mem(a, b) memset(a, b, sizeof(a))
#define forstl(i, s)  for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)// Delete Specific Element from deque

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
/*using namespace __gnu_pbds;
///   *Set.find_by_order(k)  returns a pointer to the k'th element (0 indexed)
///   Set.order_of_key(k)   returns an integer equal to the number of elements STRICTLY SMALLER than 'k'
template<typename T> using orderSet = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;*/


ll gcd(ll a, ll b) {return __gcd(a,b);}
ll lcm(ll a, ll b) {return a*(b/gcd(a,b));}

int stringTointeger(string str)
{
    int temp = 0;
    for (int i = 0; i < str.length(); i++) {
        temp = temp * 10 + (str[i] - '0');
    }
    return temp;
}


const int N = 1e5+20;
const int MOD = 1e9+7;
const int inf = 2000000000;
const ll infLL = 9000000000000000;
const ld eps=1e-6 ;// 5 decimal point same

ll arr[N];
ll tree[4*N];
ll lazy_tree[4*N];


void build(ll node, ll L, ll R)
{
    if(L==R)
    {
        tree[node]=arr[L];
        return;
    }

    ll mid=(L+R)/2;
    build(node*2,L,mid);
    build(node*2+1,mid+1,R);
    tree[node]=tree[node*2]+tree[node*2+1];
}

void update(ll node, ll L, ll R, ll l, ll r, ll value)
{
    //previous pending update
    if(lazy_tree[node]!=0)
    {
        ll val=lazy_tree[node];
        lazy_tree[node]=0;

        tree[node]+=(R-L+1)*val;
        if(L!=R)
        {
            lazy_tree[node*2]+=val;
            lazy_tree[node*2+1]+=val;
        }

    }
    if(r<L || R<l)
    {
        return ;
    }

    if(L>=l && R<=r)
    {
        tree[node]+=(R-L+1)*value;
        if(L!=R)
        {
            lazy_tree[node*2]+=value;
            lazy_tree[node*2+1]+=value;
        }
        return ;
    }

    ll mid=(L+R)/2;
    update(node*2,L,mid,l,r,value);
    update(node*2+1,mid+1,R,l,r,value);
    tree[node]=tree[node*2]+tree[node*2+1];
}


ll query(ll node, ll L, ll R, ll l, ll r)
{
    //previous pending update
    if(lazy_tree[node]!=0)
    {
        ll val=lazy_tree[node];
        lazy_tree[node]=0;

        tree[node]+=(R-L+1)*val;
        if(L!=R)
        {
            lazy_tree[node*2]+=val;
            lazy_tree[node*2+1]+=val;
        }

    }
    if(r<L || R<l)
    {
        return 0;
    }

    if(L>=l && R<=r)
    {
        return tree[node];
    }

    ll mid=(L+R)/2;
    ll x=query(node*2,L,mid,l,r);
    ll y=query(node*2+1,mid+1,R,l,r);
    return x+y;
}





int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int n,q,op,l,r,val;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    build(1,1,n);

    while(q--)
    {
        cin>>op;
        if(op==1)
        {
            cin>>l>>r;
            cout<<query(1,1,n,l,r)<<endl;
        }
        if(op==2)
        {
            cin>>l>>r>>val;
            update(1,1,n,l,r,val);
        }
    }





    return 0;


}
/*
8 3
3 1 5 0 8 3 0 0
1 4 8
2 4 8 2
1 4 8
*/

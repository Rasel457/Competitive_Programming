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


const int N = 2e5+10;
const int MOD = 1e9+7;
const int inf = 2000000000;
const ll infLL = 9000000000000000;
const ld eps=1e-6 ;// 5 decimal point same

ll arr[N];
ll tree[4*N];
int xx=1;
ll q;

void build(ll node, ll L, ll R)
{

    if(L==R)
    {
        if(L<=q)
        {
            tree[node]=0;
        }
        else
        {
            tree[node]=arr[xx];
            xx++;
        }
        return;
    }
    ll mid=(L+R)>>1;
    build(node*2,L,mid);
    build(node*2+1,mid+1,R);
    tree[node]=tree[node*2]+tree[node*2+1];
}

void update(ll node, ll L, ll R, ll pos, ll val)
{
    if(L==R)
    {
        tree[node]=val;
        return;
    }
    int mid=(L+R)>>1;

    if(pos<=mid)
    {
        update(node*2, L,mid,pos,val);
    }
    else
    {
         update(node*2+1, mid+1,R,pos,val);
    }
    tree[node]=tree[node*2]+tree[node*2+1];
}


ll query(ll node, ll L, ll R, ll l, ll r)
{
    if(l>R || L>r)
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


    ll n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }

    cin>>q;
    ll m=n+q;
    build(1,1,m);
    ll p=q;
    ll d=q;
    ll v,l,r;
    int op;
    while(d--)
    {
        cin>>op;
        if(op==1)
        {
            cin>>l>>r;
            l+=p;
            r+=p;
            ll ans=query(1,1,m,l,r);
            cout<<ans<<endl;

        }
        else if(op==2)
        {
            cin>>v;
            update(1,1,m,p,v);
            p--;
        }
    }



    return 0;


}

//https://www.spoj.com/problems/RANGESUM/
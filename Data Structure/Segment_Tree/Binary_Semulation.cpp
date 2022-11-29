
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
        tree[node]=0;
        return;
    }

    ll mid=(L+R)/2;
    build(node*2,L,mid);
    build(node*2+1,mid+1,R);
    //tree[node]=tree[node*2]+tree[node*2+1];
}

void update(ll node, ll L, ll R, ll l, ll r, ll value)
{
    if(lazy_tree[node]!=0)
    {
        ll val=lazy_tree[node];
        lazy_tree[node]=0;

        tree[node]+=val;
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
        tree[node]+=value;
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
    //tree[node]=tree[node*2]+tree[node*2+1];
}


ll query(ll node, ll L, ll R, ll l, ll r)
{
    if(lazy_tree[node]!=0)
    {
        ll val=lazy_tree[node];
        lazy_tree[node]=0;

        tree[node]+=val;
        if(L!=R)
        {
            lazy_tree[node*2]+=val;
            lazy_tree[node*2+1]+=val;
        }

    }
    if(r<L || R<l)
    {
        return 0 ;
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


    int t,cas=0;
    cin>>t;
    while(t--)
    {
        mem(tree,0);
        mem(lazy_tree,0);
        cas++;
        string s;
        cin>>s;
        string str="_";
        str+=s;
        int n=str.size()-1;
        int q;
        cin>>q;
        char com;
        int l,r,a;
        cout<<"Case "<<cas<<":"<<endl;
        while(q--)
        {
            cin>>com;
            if(com=='I')
            {
                cin>>l>>r;
                update(1,1,n,l,r,1);
            }
            if(com=='Q')
            {
                cin>>a;
                int x=query(1,1,n,a,a);
                int y=str[a]-'0';
                if(x%2==0)
                {
                    cout<<y<<endl;
                }
                else
                {
                    if(y==0)
                    {
                        cout<<1<<endl;
                    }
                    else
                    {
                        cout<<0<<endl;
                    }
                }
            }
        }
    }




    return 0;


}

//https://lightoj.com/problem/binary-simulation


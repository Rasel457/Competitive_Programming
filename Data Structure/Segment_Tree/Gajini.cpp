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
ll max_tree[4*N];
ll min_tree[4*N];

void build(ll node ,ll L, ll R)
{
    if(L==R)
    {
        max_tree[node]=arr[L];
        min_tree[node]=arr[L];
        return;
    }

    ll mid=(L+R)/2;
    build(node*2,L,mid);
    build(node*2+1,mid+1,R);
    max_tree[node]=max(max_tree[node*2],max_tree[node*2+1]);
    min_tree[node]=min(min_tree[node*2],min_tree[node*2+1]);
}

ll max_query(ll node,ll L, ll R, ll l, ll r)
{
    if(l>R || r<L)
    {
        return -inf;
    }
    if(L>=l && R<=r)
    {
        return max_tree[node];
    }

    ll mid=(L+R)/2;
    ll x=max_query(node*2,L,mid,l,r);
    ll y=max_query(node*2+1,mid+1,R,l,r);
    return max(x,y);

}

ll min_query(ll node,ll L, ll R, ll l, ll r)
{
    if(l>R || r<L)
    {
        return inf;
    }
    if(L>=l && R<=r)
    {
        return min_tree[node];
    }

    ll mid=(L+R)/2;
    ll x=min_query(node*2,L,mid,l,r);
    ll y=min_query(node*2+1,mid+1,R,l,r);
    return min(x,y);

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
        cas++;
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>arr[i];
        }

        build(1,1,n);
        ll mx=0;
        ll mn=0;
        ll ans=0;
        for(int i=1;i<=n-d+1;i++)
        {
            mx=max_query(1,1,n,i,i+d-1);
            mn=min_query(1,1,n,i,i+d-1);
            ll dif=mx-mn;
            if(dif>ans)
            {
                ans=dif;
            }
        }

        cout<<"Case "<<cas<<": "<<ans<<endl;
    }



    return 0;


}
// https://lightoj.com/problem/ghajini
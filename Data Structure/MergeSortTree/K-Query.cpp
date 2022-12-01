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


const int N = 3e4+10;
const int MOD = 1e9+7;
const int inf = 2000000000;
const ll infLL = 9000000000000000;
const ld eps=1e-6 ;// 5 decimal point same


ll arr[N];
vl mst[4*N];

void build(ll node, ll L, ll R)
{
    if(L==R)
    {
        mst[node].pb(arr[L]);
        return;
    }

    ll mid=(L+R)/2;
    build(node*2,L,mid);
    build(node*2+1,mid+1,R);

    int i=0;
    int j=0;

    while(i<mst[node*2].size() && j<mst[node*2+1].size())
    {
        if(mst[node*2][i]<=mst[node*2+1][j])
        {
            mst[node].pb(mst[node*2][i]);
            i++;
        }
        else
        {
            mst[node].pb(mst[node*2+1][j]);
            j++;
        }
    }

    while(i<mst[node*2].size())
    {
        mst[node].pb(mst[node*2][i]);
        i++;
    }

    while(j<mst[node*2+1].size())
    {
        mst[node].pb(mst[node*2+1][j]);
        j++;
    }

}



int query(ll node, ll L, ll R, ll l, ll r, ll val)
{
    if(l>R || L>r)
    {
        return 0;
    }
    if(L>=l && R<=r)
    {
        ll res=upper_bound(mst[node].begin(),mst[node].end(),val)- mst[node].begin();
        //cout<<"r "<<res<<endl;
        ll ans=mst[node].size()-res;
        //cout<<"a"<<" "<<ans<<endl;
        return ans;
    }
    ll mid=(L+R)/2;
    ll x=query(node*2,L,mid,l,r,val);
    ll y=query(node*2+1,mid+1,R,l,r,val);
    return x+y;
}





int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    ll n,q,l,r,m;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    build(1,1,n);
    cin>>q;
    while(q--)
    {
        cin>>l>>r>>m;
        ll ans=query(1,1,n,l,r,m);
        cout<<ans<<endl;
    }

    return 0;


}

//https://vjudge.net/contest/530771#problem/AO
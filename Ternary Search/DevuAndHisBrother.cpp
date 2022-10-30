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
using namespace __gnu_pbds;
///   *Set.find_by_order(k)  returns a pointer to the k'th element (0 indexed)
///   Set.order_of_key(k)   returns an integer equal to the number of elements STRICTLY SMALLER than 'k'
template<typename T> using orderSet = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;


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
const ll infLL = 90000000000000000;


ll arr[N];
ll brr[N];


ll n,m;

ll f(ll x)
{
    ll sum=0;
    for(int i=1;i<=n;i++)
    {
        if(arr[i]<x)
        {
            sum+=x-arr[i];
        }
    }

    for(int i=1;i<=m;i++)
    {
        if(brr[i]>x)
        {
            sum+=brr[i]-x;
        }
    }
    //cout<<sum<<endl;
    return sum;
}

ll ternary_search(ll l, ll r)
{
    while(r-l>3)
    {
        ll m1=l+(r-l)/3;
        ll m2=r-(r-l)/3;
        ll f1=f(m1);
        ll f2=f(m2);

        if(f1<f2)
        {
            r=m2;
        }
        else
        {
            l=m1;
        }
    }

    ll mn=infLL;
    for(int i=l;i<=r;i++)
    {
        mn=min(mn,f(i));
    }
    return mn;
}






int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);



    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    for(int i=1;i<=m;i++)
    {
        cin>>brr[i];
    }
    ll l=0;
    ll r=1000000005;
    ll ans=ternary_search(l,r);
    cout<<ans<<endl;




    return 0;

}


// https://vjudge.net/contest/522488#problem/E
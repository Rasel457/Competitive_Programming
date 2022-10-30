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


const int N = 2e5+20;
const int MOD = 1e9+7;
const int inf = 2000000000;
const ll infLL = 90000000000000000;


long double arr[N];


ll n,k;

ld f(ld x)
{
    //cout<<"Here "<<x<<endl;
    ld mx=-1;
    ld sum=0.0;
    for(int i=1;i<=n;i++)
    {
        sum+=arr[i]-x;
       // cout<<sum<<endl;
        if(sum<0)
        {
            sum=0;
        }
        mx=max(mx,sum);

    }
    sum=0;
    for(int i=1;i<=n;i++)
    {
        sum+=x-arr[i];
       // cout<<sum<<endl;
        if(sum<0)
        {
            sum=0;
        }
        mx=max(mx,sum);

    }
    return mx;


}

ld ternary_search(ld l, ld r)
{
    for(int i=1;i<=150;i++)
    {
        ld m1=l+(r-l)/3;
        ld m2=r-(r-l)/3;
        ld f1=f(m1);
        ld f2=f(m2);

        if(f1<f2)
        {
            r=m2;
        }
        else
        {
            l=m1;
        }
    }
     return f(l);
}




int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);



    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    ld l=-100005;
    ld r=100005;
    ld ans=ternary_search(l,r);
    cout<<fixed<<setprecision(15)<<ans<<endl;




    return 0;

}


// https://codeforces.com/problemset/problem/578/C
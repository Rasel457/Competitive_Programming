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
#define forstl(i, s)  for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)// Delete Specific Element from dequeue

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
///   *Set.find_by_order(k)  returns a pointer to the k'th element (0 indexed)
///   Set.order_of_key(k)   returns an integer equal to the number of elements STRICTLY SMALLER than 'k'
template<typename T> using orderSet = tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;


//ll gcd(ll a, ll b) {return __gcd(a,b);}
//ll lcm(ll a, ll b) {return a*(b/gcd(a,b));}

int stringTointeger(string str)
{
    int temp = 0;
    for (int i = 0; i < str.length(); i++) {
        temp = temp * 10 + (str[i] - '0');
    }
    return temp;
}


const int N = 1e5+20;
const ll MOD = 1000000007;
const int inf = 2000000000;
const ll infLL = 9000000000000000;
const ld eps=1e-6 ;// 5 decimal point same


int arr[N];

int f[N];//Number of tuples with GCD as multiple of i
int g[N];//Number of tuples with GCD as i


void solve()
{
    int n;
    cin>>n;
    int mx=0;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        f[arr[i]]++;

        if(arr[i]>mx)
        {
            mx=arr[i];
        }
    }

    for(int i=1;i<=mx;i++)
    {
        for(int j=i+i;j<=mx;j+=i)
        {
            f[i]+=f[j];
        }
    }

    for(int i=mx;i>=1;i--)
    {
        g[i]=f[i]*f[i];
        for(int j=i+i;j<=mx;j+=i)
        {
           g[i]-=g[j];
        }

    }

    cout<<g[1]<<endl;



}




int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T=1;

    for(int i=1;i<=T;i++)
    {
        solve();
    }

    return 0;

}


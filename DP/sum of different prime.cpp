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
/*using namespace __gnu_pbds;
///   *Set.find_by_order(k)  returns a pointer to the k'th element (0 indexed)
///   Set.order_of_key(k)   returns an integer equal to the number of elements STRICTLY SMALLER than 'k'
template<typename T> using orderSet = tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;*/


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
const ll infLL = 9000000000000000;
const ld eps=1e-6 ;// 5 decimal point same



bool isPrime[N];
vector<int>prime;

void genPrime(int n)
{
    isPrime[2]=1;
    for(int i=3;i<=n;i+=2)
    {
        isPrime[i]=1;
    }
    for(int i=3;i*i<=n;i+=2)
    {
        if(isPrime[i]==1)
        {
            for(int j=i*i;j<=n;j+=(2*i))     //Complexity O(n)
            {
                isPrime[j]=0;
            }
        }

    }
    prime.push_back(2);
    for(int i=3;i<=n;i+=2)
    {
        if(isPrime[i]==1)
        {
            prime.push_back(i);
        }
    }

}

const int maxn = 1200;
ll n,k;
ll dp[260][maxn][15];

ll print(int pos,ll sum,int cnt)
{
    if(pos==prime.size() || sum>=n || cnt>=k)
    {
         if(sum==n && cnt==k)
         {
             return 1;
         }
         else
         {
             return 0;
         }


    }
    if(dp[pos][sum][cnt]!=-1)
    {
        return dp[pos][sum][cnt];
    }
    //nibo
    sum+=prime[pos];
    ll x= print(pos+1,sum,cnt+1);
    //nobo nah
    sum-=prime[pos];
    ll y=print(pos+1,sum,cnt);

    return dp[pos][sum][cnt]= x+y;



}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    genPrime(1500);

    while(cin>>n>>k)
    {
        if(n==0 && k==0)
        {
            break;
        }
        mem(dp,-1);
        cout<<print(0,0,0)<<endl;
    }


    return 0;

}

//https://vjudge.net/problem/UVA-1213

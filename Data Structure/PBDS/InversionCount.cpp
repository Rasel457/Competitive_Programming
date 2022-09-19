#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define endl '\n'
#define pii pair<int,int>
#define pll pair<long long, long long>
#define ff first
#define ss second
#define pb push_back
#define PI 2.0 * acos(0.0)
#define mem(a, b) memset(a, b, sizeof(a))
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
///   *Set.find_by_order(k)  returns a pointer to the k'th element (0 indexed)
///   Set.order_of_key(k)   returns an integer equal to the number of elements STRICTLY SMALLER than 'k'
template<typename T> using orderSet = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll gcd(ll a, ll b) {return __gcd(a,b);}
ll lcm(ll a, ll b) {return a*(b/gcd(a,b));}

const int N = 2e5+10;
const int MOD = 1e9+7;

ll arr[N];


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        orderSet<ll>st;
        st.insert(arr[0]);
        ll invCnt=0;
        ll key=0;
        for(int i=1;i<n;i++)
        {
            st.insert(arr[i]);
            key=st.order_of_key(arr[i]+1);
            invCnt+=st.size()-key;
        }
        cout<<invCnt<<endl;

    }

    return 0;

}

// https://www.spoj.com/problems/INVCNT/



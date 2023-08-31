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
#define all(x)     x.begin(),x.end()
#define asort(x)   sort(all(x));
#define dsort(x)   sort(all(x), greater<int>())

#define forstl(i, s)  for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)// Delete Specific Element from dequeue

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
///   *Set.find_by_order(k)  returns a pointer to the k'th element (0 indexed)
///   Set.order_of_key(k)   returns an integer equal to the number of elements STRICTLY SMALLER than 'k'
template<typename T> using orderSet = tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;


ll Gcd(ll a, ll b) {return __gcd(a,b);}
ll lcm(ll a, ll b) {return a*(b/Gcd(a,b));}

int stringTointeger(string str)
{
    int temp = 0;
    for (int i = 0; i < str.length(); i++) {
        temp = temp * 10 + (str[i] - '0');
    }
    return temp;
}


const int N = 1e5+20;
const int maxn = 120;
const int MOD = 1e9+7;
const int inf = 2000000000;
const ll infLL = 9000000000000000;
const ld eps=1e-7;// 5 decimal point same

int a[N];

void solve(int caseNo)
{
   int n;
   cin>>n;
   for(int i=0;i<n;i++)
   {
       cin>>a[i];
   }

   for(int i=1;i<n;i++)
   {
       int flag=0;
       for(int j=0;j<n-i;j++)
       {
           if(a[j]>a[j+1])
           {
               swap(a[j],a[j+1]);
               flag=1;
           }
       }
       if(flag==0)
       {
           break;
       }
   }
   cout<<"Sorted array"<<endl;

   for(int i=0;i<n;i++)
   {
       cout<<a[i]<<" ";
   }


}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int T;
    cin>>T;

    for(int i=1;i<=T;i++)
    {
        solve(i);
    }

    return 0;

}

/*
1
8
1 5 6 3 8 4 7 2

1
7
38 27 43 3 9 82 10
*/

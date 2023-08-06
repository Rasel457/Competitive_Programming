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
//ll lcm(ll a, ll b) {return a*(b/gcd(a,b));}

ll stringTointeger(string str)
{
    ll temp = 0;
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
const ld eps=1e-6 ;// 5 decimal point same

int a[N];


void solve(int caseNo)
{
       int n;
       cin>>n;

       for(int i=0;i<n;i++)
       {
           cin>>a[i];
       }

       if(n<2)
       {
           cout<<"Invalid Input"<<endl;
           return;
       }

       int first=INT_MAX;
       int second=INT_MAX;

       for(int i=0;i<n;i++)
       {
           if(a[i]<first)
           {
               second=first;
               first=a[i];

           }
           else if(a[i]<second && a[i]!=first)
           {
               second=a[i];
           }

       }

       if(second==INT_MAX)
       {
           cout<<"We don't have 2nd smallest item in array"<<endl;
       }
       else
       {
           cout<<"The 2nd smallest : "<<second<<endl;
       }


}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int T=1;
    //cin>>T;

    for(int i=1;i<=T;i++)
    {
        solve(i);
    }

    return 0;

}

//https://prepinsta.com/c-program/find-second-smallest-element-in-an-array-using-c/

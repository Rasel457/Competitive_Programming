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


const int N = 1e5+10;
const int MOD = 1e9+7;

ll  arr[N];




int main()
{
    

     ll n,s;

     while(scanf("%lld %lld",&n,&s)!=EOF)
     {
         ll total=0;
         /*if(n==0 && s==0)
         {
             break;
         */
         for(int i=0;i<n;i++)
         {
             cin>>arr[i];
             total+=arr[i];
         }

         ll currSum=0;
         queue<ll>q;
         ll mn=INT_MAX;

         for(int i=0;i<n;i++)
         {
             currSum+=arr[i];
             q.push(i);
             while(currSum>=s )
             {
                  mn=min(mn,(i-q.front())+1);
                  currSum=currSum-arr[q.front()];
                  q.pop();
             }


         }
         if(total<s)
         {
             mn=0;
         }
         cout<<mn<<endl;


     }


    return 0;
}
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3562






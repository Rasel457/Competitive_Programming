 Home
Problem
Status
Contest
Workbook
User
Group
Forum
Logout
Rasel_aiub
Ternary Search :

https://cp-algorithms.com/num_methods/ternary_search.html
Begin: 2022-10-22 23:00 BST
Topic Practice (Ternary Search)
End: 2022-11-06 23:00 BST
194:12:55
Elapsed: 194:12:56RunningRemaining: 165:47:03
Overview
Problem
Status
Rank (194:12:46)
0 Comments
Previous12345…Next
Run ID	Username
Rasel_aiub
Prob

B - Race Time!
Result

All
Time
(ms)	Mem
(MB)	Length	Lang

All
Submit Time
39280613	
Rasel_aiub
B
Accepted
80	5.4	2059	
C++
9 hr ago
39280603	
Rasel_aiub
B
Wrong Answer
2062	
C++
9 hr ago
39280581	
Rasel_aiub
B
Accepted
70	5.4	2063	
C++
9 hr ago
39280545	
Rasel_aiub
B
Wrong Answer
2058	
C++
9 hr ago
39280536	
Rasel_aiub
B
Wrong Answer
2058	
C++
9 hr ago
39280520	
Rasel_aiub
B
Wrong Answer
2062	
C++
9 hr ago
     
All Copyright Reserved © 2010-2022 Xu Han
Server Time: 2022-10-31 01:12:56 BST

#39280613 | Rasel_aiub's solution for [Problem B]
Status
Accepted
Time
80ms
Memory
5427kB
Length
2059
Lang
C++14 (gcc 11.1.0)
Submitted
2022-10-30 16:12:40
Open

Share text 

Copy Code
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


ll s[N];
ll d[N];

ll n,k;

ld f(ld t)
{
    ld mx=-1*inf,mn=inf;
    for(int i=1;i<=n;i++)
    {
        ld p=(s[i]*t)+d[i];
        mx=max(mx,p);
        mn=min(mn,p);
    }
    return mx-mn;

}

ld ternary_search(ld l, ld r)
{
    for(int i=1;i<=100;i++)
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



    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i]>>d[i];
    }
    ld l=0;
    ld r=k;
    ld ans=ternary_search(l,r);
    cout<<fixed<<setprecision(6)<<ans<<endl;




    return 0;

}


// https://vjudge.net/contest/522488#problem/B

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


const int N = 1e6+10;
const int MOD = 1e9+7;

ll  arr[N];








int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    ll p,c,cas=0;
    while(cin>>p>>c)
    {
        if(p==0 && c==0)
        {
            break;
        }
        cas++;
        deque<ll>q;
        for(int i=1;i<=p &&i<=1000;i++)
        {
            q.push_back(i);
        }
        cout<<"Case "<<cas<<":"<<endl;
        char ch;
        ll x;
        while(c--)
        {
            cin>>ch;
            if(ch=='N')
            {
                ll a=q.front();
                q.pop_front();
                q.push_back(a);
                cout<<a<<endl;
            }
            else
            {
                cin>>x;
                forstl(i,q)
                {
                    if(*i==x)
                    {
                        q.erase(i);
                        break;
                    }
                }
                q.push_front(x);

            }
        }
    }
    return 0;
}

////https://vjudge.net/problem/UVA-12207





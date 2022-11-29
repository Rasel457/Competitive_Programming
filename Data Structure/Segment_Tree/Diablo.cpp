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
/*using namespace __gnu_pbds;
///   *Set.find_by_order(k)  returns a pointer to the k'th element (0 indexed)
///   Set.order_of_key(k)   returns an integer equal to the number of elements STRICTLY SMALLER than 'k'
template<typename T> using orderSet = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;*/


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


const int N = 1e5+50002;
const int MOD = 1e9+7;
const int inf = 2000000000;
const ll infLL = 9000000000000000;
const ld eps=1e-6 ;// 5 decimal point same

int arr[N];
int n;

int tree[4*N];

void build(ll node, ll L, ll R)
{
    if(L==R)
    {
        if(L<=n)
        {
            tree[node]=1;
        }
        else
        {
            tree[node]=0;
        }
        return;

    }
    ll mid=(L+R)>>1;
    build(node*2,L,mid);
    build(node*2+1,mid+1,R);
    tree[node]=tree[node*2]+tree[node*2+1];
}

void update(int node,int L, int R, ll pos,ll val)
{
    if(L==R)
    {
        tree[node]=val;
        return;
    }
    int mid=(L+R)>>1;

    if(pos<=mid)
    {
        update(node*2,L,mid,pos,val);
    }
    else
    {
        update(node*2+1,mid+1,R,pos,val);
    }
    tree[node]=tree[node*2]+tree[node*2+1];

}

ll query(int node,int L,int R, ll K)
{
    if(L==R)
    {
        return L;
    }
    int mid=(L+R)>>1;
    if(tree[node*2]>=K)
    {
        return query(node*2,L,mid,K);
    }
    else
    {
        return query(node*2+1,mid+1,R,K-tree[node*2]);
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t,cas=0;
    cin>>t;
    while(t--)
    {
        cas++;
        mem(tree,0);
        ll q;
        cin>>n>>q;
        int m=n+q;
        for(int i=1;i<=n;i++)
        {
            cin>>arr[i];
            //update(1,1,m,i,1);
        }
        build(1,1,m);
        char op;
        ll k,p,curr=n,cnt=n;
        cout<<"Case "<<cas<<":"<<endl;
        while(q--)
        {
            cin>>op;
            if(op=='c')
            {
                cin>>k;
                if(k>cnt)
                {
                    cout<<"none"<<endl;
                    continue;
                }
                int idx=query(1,1,m,k);
                cout<<arr[idx]<<endl;
                update(1,1,m,idx,0);
                cnt--;

            }
            else if(op=='a')
            {
                cin>>p;
                curr++;
                cnt++;
                arr[curr]=p;
                update(1,1,m,curr,1);

            }
        }
    }



    return 0;


}
//https://lightoj.com/problem/diablo
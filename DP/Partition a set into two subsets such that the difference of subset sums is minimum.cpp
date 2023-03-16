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


ll gcd(ll a, ll b) {return __gcd(a,b);}
//ll lcm(ll a, ll b) {return a*(b/gcd(a,b));}

int stringTointeger(string str)
{
    int temp = 0;
    for (int i = 0; i < str.length(); i++) {
        temp = temp * 10 + (str[i] - '0');
    }
    return temp;
}


const int N = 1e3+500;
const int MOD = 1e9+7;
const int inf = 2000000000;
const ll infLL = 9000000000000000;
const ld eps=1e-6 ;// 5 decimal point same 

int minSubsetSumDifference(vector<int>& a, int n)
{
	ll totsum=0;
	for(int i=0;i<n;i++)
	{
		totsum+=a[i];
	}
	int k=totsum;
	vector<vector<bool>>dp(n,vector<bool>(k+1,0));

	for(int i=0;i<n;i++)
	{
		dp[i][0]=true;
	}
	dp[0][a[0]]=true;

	for(int idx=1;idx<n;idx++)
	{
		for(int target=1;target<=k;target++)
		{
			bool not_take=dp[idx-1][target];
			bool take=false;
			if(target>=a[idx])
			{
				take=dp[idx-1][target-a[idx]];
			}
			dp[idx][target]=take|not_take;
	
		}	
	}

	ll mini=1e9;

	for(int s1=0;s1<=totsum/2;s1++)
	{
		if(dp[n-1][s1]==true)
		{
			mini=min(mini,abs((totsum-s1)-s1));
		}
	}
	return mini;

}
//https://www.codingninjas.com/codestudio/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494?leftPanelTab=0
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

int arr[N];


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int a[] = { 5,-4,-2,6,-1 };
    int n = sizeof(a) / sizeof(a[0]);

    int mxsum=INT_MIN;
    int cursum=0;
    int start=0,end=0,idx=0;
    for(int i=0;i<n;i++)
    {
        cursum+=a[i];
        if(mxsum<cursum)
        {
            mxsum=cursum;
            start=idx;
            end=i;

        }
        if(cursum<0)
        {
            cursum=0;
            idx=i+1;;
        }
    }
    cout<<"Maximum Sum "<<mxsum<<endl;
    cout<<"Start Index "<<start<<endl;
    cout<<"End Index "<<end<<endl;

    return 0;
}

//https://leetcode.com/problems/maximum-subarray/submissions/







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

void Merge(int a[],int l,int mid,int r)
{
    int i,j,k;
    int n1 = mid - l + 1;
    int n2 = r - mid;

    //cout<<n1<<" "<<n2<<endl;

    // Create temp arrays
    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for(i=0;i<n1;i++)
    {
        L[i]=a[l+i];
    }

    for(j=0;j<n2;j++)
    {
        R[j]=a[mid+1+j];
    }

    // Merge the temp arrays back into arr[l..r
    i=0;
    j=0;
    k=l;

    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        {
            a[k]=L[i];
            i++;
        }
        else
        {
            a[k]=R[j];
            j++;

        }
        k++;
    }

    // Copy the remaining elements of L[],
    // if there are any
    while(i<n1)
    {
        a[k]=L[i];
        i++;
        k++;
    }
    // Copy the remaining elements of R[],
    // if there are any
    while(j<n2)
    {
        a[k]=R[j];
        j++;
        k++;
    }
}


void mergeSort(int a[],int l,int r)
{
    if(l>=r)
    {
        return;
    }

    int mid=l+(r-l)/2;
   // cout<<"left "<<l<<" "<<mid<<endl;
    mergeSort(a,l,mid);
    //cout<<"right "<<mid+1<<" "<<r<<endl;
    mergeSort(a,mid+1,r);
    //cout<<l<<" "<<mid<<" "<<r<<endl;
    Merge(a,l,mid,r);

}




void solve(int caseNo)
{
   int n;
   cin>>n;
   for(int i=0;i<n;i++)
   {
       cin>>a[i];
   }

   mergeSort(a,0,n-1);

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

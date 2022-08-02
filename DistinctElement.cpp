#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define endl '\n'

const int N = 1e5+5;
const int MOD = 1e9+7;
const int maxn = 505;

int arr[N];
int Idx[N];                                        // https://codeforces.com/contest/368/problem/B
int check[N];
int n,m;
void precal()
{
    int cnt=1;
    for(int i=n;i>=1;i--)
    {
        if(check[arr[i]]==0)
        {
            Idx[i]=cnt;
            check[arr[i]]=1;
            cnt++;
        }
        else{
            Idx[i]=cnt-1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    precal();

    int l;
    while(m--)
    {
        cin>>l;
        cout << Idx[l]<< endl;
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;

const int N = 1e5+20;

int arr[N];
int f[N];

void solve()
{
    int n;
    cin>>n;
    int mx=0;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        f[arr[i]]++;

        if(arr[i]>mx)
        {
            mx=arr[i];
        }
    }

    for(int i=1;i<=mx;i++)
    {
        for(int j=i+i;j<=mx;j+=i)
        {
            f[i]+=f[j];
        }
    }

    for(int i=1;i<=n;i++)
    {
        cout<<f[i]<<endl;
    }
}




int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T=1;

    for(int i=1;i<=T;i++)
    {
        solve();
    }

    return 0;

}


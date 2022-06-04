#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define endl '\n'


const int N = 1e7+5;
const int MOD = 1e9+7;

double eps=1e-6 ;// 5 decimal point same

double Multiply(double mid,int n)
{
    double ans=1;
    for(int i=0;i<n;i++)
    {
        ans*=mid;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    double x;
    int n;
    cin>>x>>n;
    double lo=0,hi=x,mid;
    while(hi-lo>eps)
    {
        mid=(lo+hi)/2;
        if(Multiply(mid,n)<x)
        {
            lo=mid;
        }
        else
        {
            hi=mid;
        }
    }
    cout<<hi<<endl;
    //cout<<pow(x,1.0/n);//Check



    return 0;
}


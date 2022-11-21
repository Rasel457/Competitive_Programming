#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define endl '\n'


double eps=1e-6 ;// 5 decimal point same

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    double x;
    cin>>x;
    double lo=0,hi=x,mid;
    while(hi-lo>eps)
    {
        mid=(lo+hi)/2;
        if(mid*mid<=x)
        {
            lo=mid;
        }
        else
        {
            hi=mid;
        }
    }
    cout<<lo<<endl;
    //cout<<pow(x,1.0/2);



    return 0;
}


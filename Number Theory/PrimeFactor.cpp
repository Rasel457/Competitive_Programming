#include <bits/stdc++.h>
using namespace std;

void PrimeFact(int n)
{
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            int cnt=0;
            while(n%i==0)
            {
                n/=i;
                cnt++;
            }
            cout<<i<<"^"<<cnt<<",";
        }
    }
    if(n!=1)
    {
        cout<<n<<"^"<<"1";
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        PrimeFact(n);
    }
    return 0;
}

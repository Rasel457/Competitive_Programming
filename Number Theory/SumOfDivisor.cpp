#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;

LL SOD[10000005];

void SumOfDivisors(LL n)
{
    for(int i=1; i<=n;i++)
    {
        for(int j=i ;j<=n ;j+=i)
            {
                SOD[j]+=i;
            }
    }
}


int main()
{
    LL n;
    cin>>n;
    SumOfDivisors(n);
    cout<<SOD[10]<<endl;
}

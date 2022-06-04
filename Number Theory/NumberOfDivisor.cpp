#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;

int NOD[10000005];

void NumberOfDivisors(LL n)
{
    for(int i=1; i<=n;i++)
    {
        for(int j=i ;j<=n ;j+=i)
            NOD[j]++;
    }
}

int main()
{
    LL n;
    cin>>n;
    NumberOfDivisors(n);
    cout<<NOD[100]<<endl;
}

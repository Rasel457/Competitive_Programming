#include <bits/stdc++.h>

using namespace std;
typedef long long int LL;

int main()
{

    LL n;
    cout<<"Enter any number : "; //n maximum 10e6 
    cin>>n;
    LL prime[n+1];
    prime[0]=0;
    prime[1]=0;
    for(LL i=2;i<=n;i++)
   {
        prime[i]=1;
   }
   for(LL i=2;i*i<=n;i++)
   {
       if(prime[i]==1)
       {
            for(LL j=2;i*j<=n;j++)
            {
                prime[i*j]=0;
            }
        }
   }
   for(int i=0;i<=n;i++)
   {
       if(prime[i]==1)
       {

           cout<<i<<" ";
       }

   }
    return 0;
}



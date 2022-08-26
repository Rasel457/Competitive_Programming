                               ///number of prime with a given range///
#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
int main()
{
    LL q;
    cout<<"Number of query : ";
    cin>>q;
    cout<<"Enter any number : ";
    LL n;
    cin>>n;
    LL sum=0;
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
        sum+=prime[i];
        prime[i]=sum;
        //cout<<prime[i]<<" ";
    }
    cout<<endl;

   while(q--)
   {
        LL l,r;
        cout<<"Enter two number: ";
        cin>>l>>r;
        cout<<prime[r]-(prime[l-1])<<endl;

   }



 return 0;

}

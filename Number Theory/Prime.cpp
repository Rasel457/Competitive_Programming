#include <bits/stdC++.h>
using namespace std;

int Isprime(int n)
{
    if(n<=1)
    {
        return 0;
    }
    else
    {
        for(int i=2;i*i<=n;i++)
        {
            if(n%i==0)
            {
                return 0;
            }
            else{
                return 1;
            }
        }
    }
}

int main()
{
    int n;
    cout << "Enter a number: " ;
    cin>>n;
    int m=Isprime(n);
    /*if(n<=1)
    {
        Isprime=false;
    }
    else{
        for(int i=2;i*i<=n;i++)
        {
            if(n%i==0)
            {
                Isprime=false;
            }
        }
    }
    if(Isprime)
    {
        cout<<n <<" is a Prime number";
    }
    else{
        cout<<n<<" is not a prime number";
    }*/

    if(m==1)
    {
        cout<<n <<" is a Prime number";
    }
    else
    {
        cout<<n<<" is not a prime number";
    }

    return 0;
}

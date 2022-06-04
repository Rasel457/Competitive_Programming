#include<bits/stdc++.h>
using namespace std;
#define ll long long int

/*string to_base(int number,int base)   // Decimal to any base
{
    string bases="0123456789ABCDEF";
    string result="";
    while(number>0)
    {
        result=bases[number%base]+result;
        number/=base;
    }
    return result;
}*/

int decimalToAnyBase(int n,int b)
{
    int ans=0;
    int power=1;

    while(n!=0)
    {
        int r=n%b;
        n/=b;
        ans+=r*power;
        power*=10;
    }
    return ans;
}

int anyBaseToDecimal(int n,int b)
{
    int ans=0;
    int power=1;

    while(n!=0)
    {
        int r=n%10;
        //ans+=(r*pow(b,power++));
        n/=10;
        ans+=r*power;
        power*=b;
    }
    return ans;
}


int main()
{
    int num,base1,base2;
    cin>>num>>base1>>base2;
    int decnum=anyBaseToDecimal(num,base1);
    int ans=decimalToAnyBase(decnum,base2);
    //string ans=to_base(decnum,base2);
    cout<<ans;
}

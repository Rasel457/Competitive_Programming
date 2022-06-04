#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;

long long powerMod(long long number, long long power, long long mod)
{
    LL ret = 0;
    if (power == 0)
        return 1LL % mod;
    if (power == 1)
        return number % mod;
    if (power % 2 == 0)
    {
        ret = powerMod(number, power / 2, mod);
        ret = (ret % mod * ret % mod) % mod;
        return ret % mod;
    }
    else
    {
        ret = powerMod(number, power / 2, mod);
        ret = (ret % mod * ret % mod * number % mod) % mod;
        return ret % mod;
    }
}

int main()
{
    LL number,power,mod;
    cin>>number>>power>>mod;
    LL bigmod=powerMod(number,power,mod);
    cout<<bigmod;
}

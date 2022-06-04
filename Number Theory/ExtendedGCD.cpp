#include <bits/stdc++.h>
using namespace std;
#define ll long long

pair <int, int> extended_gcd(int a, int b)
{
    if(b==0)
    {
        return {1,1};
    }
    pair <int, int>p1=extended_gcd(b,a%b);
    int x=p1.second;   //y1
    int y=p1.first-(a/b)*p1.second; //y=x1-(a/b)*y1
    return {x,y};
}

int main()
{
    int a,b;
    cin>>a>>b;
    pair <int, int>p= extended_gcd(a,b);
    cout<<p.first<<" "<<p.second;
}

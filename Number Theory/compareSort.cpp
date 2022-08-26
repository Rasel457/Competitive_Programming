#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double

/*bool should_i_swap(int a,int b)
{
    if(a>b){
        return true;
    }
    return false;
}*/

bool cmp(pair<int,int> a,pair<int,int>b)
{
    if(a.first!=b.first){
        return a.first<b.first;

    }
    return a.second>b.second;
}

int main()
{
    int n;
    cin>>n;
    vector<pair<int,int>>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i].first>>v[i].second ;
    }
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<n;i++)
    {
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }
    cout<<endl;
}

/*
6
4 3
5 5
5 3
25 6
7 9
8 5
https://vjudge.net/contest/487692#problem/H
https://vjudge.net/contest/499601#problem/Q
https://lightoj.com/problem/false-ordering
*/




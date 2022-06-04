#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    int lo=0,hi=v.size()-1;
    int mid;
    int value;
    cin>>value;
    while(hi-lo>1)
    {
        mid=(lo+hi)/2;
        if(v[mid]<value)
        {
            lo=mid+1;
        }
        else{
            hi=mid;
        }
    }
    if(v[lo]==value)
    {
        cout<<lo<<endl;
    }
    else if(v[hi]==value)
    {
        cout<<hi<<endl;
    }
    else
    {
        cout<<"NOT FOUND"<<endl;
    }
}

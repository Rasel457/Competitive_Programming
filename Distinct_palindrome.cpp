#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define endl '\n'

const int N = 5e5+5;
const int MOD = 1e9+7;
const int maxn = 22;

/*ll StringToInt(string str)
{
    ll temp = 0;
    for (int i = 0; i < str.length(); i++) {
        temp = temp * 10 + (str[i] - '0');
    }
    return temp;
}*/
int arr[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int t;
    cin>>t;
    while(t--)
    {
        int n;
        int x;
        cin>>n>>x;
        int b=x;
        if(x==1)
        {
            for(int i=0;i<n;i++)
            {
                cout<<"a";
            }
            cout<<endl;
        }
        else if(n==x)
        {
            cout<<"-1"<<endl;
        }
        else
        {

            string str="";
            char ch='a';
            for(int i=0;i<(n/2);i++)
            {
                if(x>0)
                {
                    str+=ch;
                    ch++;
                    x--;
                }
                else
                {
                    str+=str[str.size()-1];
                }

            }
            string ss=str;
            reverse(str.begin(),str.end());

            if(n%2==0)
            {
                int m=n/2;

                if(b<=m)
                {
                    cout<<ss<<str<<endl;
                }
                else
                {
                    cout<<"-1"<<endl;
                }
            }
            else
            {
                int y=(n+1)/2;
                if(b<=y)
                {
                    if(x>0)
                    {
                        cout<<ss<<"z"<<str<<endl;
                    }
                    else
                    {
                        cout<<str<<ss[0]<<ss<<endl;
                    }

                }
                else
                {
                    cout<<"-1"<<endl;
                }
            }
        }

    }

    return 0;
}


https://www.codechef.com/START43C/problems/DISPAL


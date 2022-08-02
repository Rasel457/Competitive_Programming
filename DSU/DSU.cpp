#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define endl '\n'

const int N = 5e5+5;
const int MOD = 1e9+7;
const int maxn = 505;
const int MX = 100;

int parent[MX];

void makeSet(int a)
{
    parent[a]=a;
}
void init()
{
    for(int i=1;i<=8;i++)
    {
        makeSet(i);
    }
}
 bool flag=false;
int Find(int n)
{
    if(flag==true)
    {
         cout<<"called with "<<n<<endl;
    }

    if(n==parent[n])return n;
    return parent[n]=Find(parent[n]);
}

void Union(int a, int b)
{
    int p=Find(a);
    int q=Find(b);

    if(p!=q)
    {
        parent[q]=p;
    }
}
bool isFriend(int a,int b)
{
    int p=Find(a);
    int q=Find(b);
    return (p==q);
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();
    /*Union(1,2);
    Union(2,3);
    Union(3,4);
    Union(4,5);
    Union(5,6);
    Union(6,7);
    Union(7,8);*/

    Union(7,8);
    Union(6,7);
    Union(5,6);
    Union(4,5);
    Union(3,4);
    Union(2,3);
    Union(1,2);
    /*for(int i=1;i<=8;i++)
    {
        cout<<"Parent of "<<i<<" is "<<parent[i]<<endl;
    }
    cout<<Find(1)<<" "<<Find(3)<<endl;
    if(isFriend(4,7))
    {
        cout<<"Friend"<<endl;
    }
    else
    {
        cout<<"Not Friend"<<endl;
    }*/
    flag=true;
    Find(4);
    cout<<"-----"<<endl;
    Find(4);
    cout<<"-----"<<endl;
    Find(4);
    cout<<"-----"<<endl;


    return 0;


}


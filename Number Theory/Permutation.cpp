#include<iostream>
using namespace std;
#define ll long long int
#define ld long double

int used[20],number[20];
void permutation(int pos,int n)
{
    //cout<<"permutation call("<<pos<<" "<<n<<endl;
    if(pos==n+1)
    {
        for(int i=1;i<=n;i++)
        {
            cout<<number[i]<<" ";
        }
        cout<<endl;
    }

    for(int i=1;i<=n;i++)
    {
        if(used[i]==0)
        {
            //cout<<"I: "<<i<<endl;//i=1,i=2
            //cout<<"permutation jaita thake call hoise("<<pos<<" "<<n<<endl;
            used[i]=1;          // u[1]=1,u[2]=1,u[3]=3
            number[pos]=i;      // n[1]=1,n[2]=2,n[3]=3
            permutation(pos+1,n);//p(3,3) p(4,3)
             //cout<<"I: "<<i<<endl;
            //cout<<"Return ar por("<<pos<<" "<<n<<endl;
            used[i]=0;
        }
    }
}

int main()
{
    int n;
    cin>>n;
    permutation(1,n);
}

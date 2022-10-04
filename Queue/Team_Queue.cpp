#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define endl '\n'
#define pii pair<int,int>
#define pll pair<long long, long long>
#define ff first
#define ss second
#define pb push_back
#define PI 2.0 * acos(0.0)
#define mem(a, b) memset(a, b, sizeof(a))

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
///   *Set.find_by_order(k)  returns a pointer to the k'th element (0 indexed)
///   Set.order_of_key(k)   returns an integer equal to the number of elements STRICTLY SMALLER than 'k'
template<typename T> using orderSet = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;


ll gcd(ll a, ll b) {return __gcd(a,b);}
ll lcm(ll a, ll b) {return a*(b/gcd(a,b));}

int stringTointeger(string str)
{
    int temp = 0;
    for (int i = 0; i < str.length(); i++) {
        temp = temp * 10 + (str[i] - '0');
    }
    return temp;
}


const int N = 1e6+10;
const int MOD = 1e9+7;

ll  arr[N];
queue<int>teamElement[1005];
int belongTo[N];




int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t,cas=0;
    while(cin>>t)
    {
        if(t==0)
        {
            break;
        }
        int numOfEle;
        int elem;
        for(int i=0;i<t;i++)
        {
            while(!teamElement[i].empty())
            {
                teamElement[i].pop();
            }
            cin>>numOfEle;
            while(numOfEle--)
            {
                cin>>elem;
                belongTo[elem]=i;
            }
        }
        cas++;
        queue<int>team;
        string command;
        int num;
        cout<<"Scenario #"<<cas<<endl;

        while(cin>>command)
        {
            if(command[0]=='S')
            {
                break;
            }
            if(command[0]=='E')
            {
                cin>>num;
                int tem=belongTo[num];
                if(teamElement[tem].empty())
                {
                    team.push(tem);
                }
                teamElement[tem].push(num);
            }
            else
            {
                int a=team.front();
                cout<<teamElement[a].front()<<endl;
                teamElement[a].pop();
                if(teamElement[a].empty())
                {
                    team.pop();
                }
            }
        }
        cout<<endl;
    }

    return 0;
}

//https://vjudge.net/problem/UVA-540





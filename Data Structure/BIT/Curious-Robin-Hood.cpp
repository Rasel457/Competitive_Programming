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


ll gcd(ll a, ll b) {return __gcd(a,b);}
ll lcm(ll a, ll b) {return a*(b/gcd(a,b));}

const int N = 1e5+10;
const int MOD = 1e9+7;

ll arr[N];
ll BIT[N];
int n;
void update(int ind, ll val){///add 'val' to index 'ind'
        while(ind<=n){
            BIT[ind]+=val;
            ind+=(ind&-ind);
        }
}
void update1(int ind, ll val){///add 'val' to index 'ind'
        ll dif=val-arr[ind];
        ll a=ind;
        while(ind<=n){
            //cout<<ind<<endl;
            BIT[ind]+=dif;
            ind+=(ind&-ind);
        }
        arr[a] = val;
}

ll query(int ind){///returns Sum of elements 1...ind
        ll ret=0;
        while(ind>0){
            ret+=BIT[ind];
            ind-=(ind&-ind);
        }
        return ret;
}

 ll range_query(int l, int r){///Sum of elements at index l...r
    	return query(r)-query(l-1);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t,cas=0;
    cin>>t;
    while(t--)
    {
        cas++;
        int q;
        cin>>n>>q;
        mem(BIT,0);
        for(int i=1;i<=n;i++)
        {
            cin>>arr[i];
            update(i,arr[i]);
        }

        int op,j,k,u,a,b;
        cout<<"Case "<<cas<<":"<<endl;
        while(q--)
        {
            cin>>op;
            if(op==1)
            {
                cin>>j;
                j++;
                ll res=query(j)-query(j-1);
                cout<<res<<endl;
                update(j, -res);
            }
            else if(op==2)
            {
                cin>>k>>u;
                k++;
                update(k,u);
            }
            else if(op==3)
            {
                cin>>a>>b;
                a++;
                b++;
                ll ans=range_query(a,b);
                cout<<ans<<endl;
            }

        }
    }

    return 0;

}

// https://vjudge.net/contest/512497#problem/F





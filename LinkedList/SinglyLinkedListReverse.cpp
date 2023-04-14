#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define endl '\n'
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<pii>
#define vll vector<pll>
#define ff first
#define ss second
#define pb push_back
#define PI 2.0 * acos(0.0)
#define mem(a, b) memset(a, b, sizeof(a))
#define forstl(i, s)  for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)// Delete Specific Element from dequeue
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
///   *Set.find_by_order(k)  returns a pointer to the k'th element (0 indexed)
///   Set.order_of_key(k)   returns an integer equal to the number of elements STRICTLY SMALLER than 'k'
template<typename T> using orderSet = tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;


ll gcd(ll a, ll b) {return __gcd(a,b);}
//ll lcm(ll a, ll b) {return a*(b/gcd(a,b));}

int stringTointeger(string str)
{
    int temp = 0;
    for (int i = 0; i < str.length(); i++) {
        temp = temp * 10 + (str[i] - '0');
    }
    return temp;
}


const int N = 1e4+20;
const int maxn = 120;
const int MOD = 1e9+7;
const int inf = 2000000000;
const ll infLL = 9000000000000000;
const ld eps=1e-6 ;// 5 decimal point same

typedef struct node Node;

struct node
{
    int data;
    Node *link;
} ;

void LinkedListTraversal(Node *ptr)
{
    while(ptr!=NULL)
    {
        cout<<"Element : "<<ptr->data<<endl;
        ptr=ptr->link;
    }
}

Node *Reverse(Node *head)
{
    Node *prev=NULL;
    Node *next=NULL;

    while(head!=NULL)
    {
        next=head->link;
        head->link=prev;
        prev=head;
        head=next;


    }
    head=prev;
    return head;
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    Node *head=(Node *)malloc(sizeof(Node));
    Node *second=(Node *)malloc(sizeof(Node));
    Node *third=(Node *)malloc(sizeof(Node));
    Node *fourth=(Node *)malloc(sizeof(Node));

    head->data=4;
    head->link=second;

    second->data=3;
    second->link=third;

    third->data=8;
    third->link=fourth;

    fourth->data=1;
    fourth->link=NULL;

    cout<<"Linked List Before Reversing "<<endl;
    LinkedListTraversal(head);
    cout<<endl;

    cout<<"Linked List After Reversing "<<endl;
    head=Reverse(head);
    LinkedListTraversal(head);



    return 0;
}

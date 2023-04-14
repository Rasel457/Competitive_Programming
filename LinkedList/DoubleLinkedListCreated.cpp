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
    Node *prev;
    int data;
    Node *next;

};

void LinkedListTraversal(Node *ptr)
{
    int i=1;
    while(ptr!=NULL)
    {
        cout<<"Element "<<i<<" : "<<ptr->data<<endl;
        ptr=ptr->next;
        i++;
    }

}

Node *AddtoEmpty(Node *head,int data)
{
    Node *temp=(Node *)malloc(sizeof(Node));

    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    head=temp;

    return head;

}


Node *InsertAtEnd(Node *head,int data)
{
    Node *temp=(Node *)malloc(sizeof(Node));

    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;

    Node *ptr=head;

    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=temp;
    temp->prev=ptr;

    return head;

}

Node *CreateList(Node *head)
{
    int n,data;

    printf("Enter the numbers of nodes: ");
    scanf("%d",&n);
    if(n==0)
    {
        return head;
    }
    printf("Enter the element for node 1: ");
    scanf("%d",&data);


    head=AddtoEmpty(head,data);

    for(int i=1;i<n;i++)
    {
        printf("Enter the element for node %d: ",i+1);
        scanf("%d",&data);
        head=InsertAtEnd(head,data);
    }
    return head;

}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    /*Node *head=(Node *)malloc(sizeof(Node));
    head->prev=NULL;
    head->data=45;
    head->next=NULL;
    cout<<"Before Insertion "<<endl;
    LinkedListTraversal(head);*/

    Node *head=NULL;
    head=CreateList(head);

    LinkedListTraversal(head);

    return 0;
}

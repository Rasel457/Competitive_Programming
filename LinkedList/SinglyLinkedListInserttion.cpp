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

Node *insertAtFirst(Node *head,int data)
{
    Node *ptr=(Node *)malloc(sizeof(Node));
    ptr->data=data;
    ptr->next=head;

    return ptr;

}

Node *insertAtIndex(Node *head,int data,int index)
{
    Node *ptr=(Node *)malloc(sizeof(Node));
    Node *p=head;

    int i=0;
    while(i!=index-1)
    {
        p=p->next;
        i++;
    }

    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;

    return head;

}

Node *insertAtEnd(Node *head,int data)
{
    Node *ptr=(Node *)malloc(sizeof(Node));
    Node *p=head;

    while(p->next!=NULL)
    {
        p=p->next;
    }

    ptr->data=data;
    p->next=ptr;
    ptr->next=NULL;

    return head;

}

Node *insertAfterNode(Node *head,Node *prevNode,int data)
{
    Node *ptr=(Node *)malloc(sizeof(Node));

    ptr->data=data;
    ptr->next=prevNode->next;
    prevNode->next=ptr;
    return head;

}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //allocate memory for nodes in the linked list in heap
    Node *head=(Node *)malloc(sizeof(Node));
    Node *second=(Node *)malloc(sizeof(Node));
    Node *third=(Node *)malloc(sizeof(Node));
    Node *fourth=(Node *)malloc(sizeof(Node));

    // link first and second node
    head->data=7;
    head->next=second;

    // link second and third node
    second->data=11;
    second->next=third;

    // link third and fourth node
    third->data=41;
    third->next=fourth;

    // terminate the list at third list
    fourth->data=66;
    fourth->next=NULL;

    cout<<"Before Insertion "<<endl;
    LinkedListTraversal(head);

    /*Insert at First
    head=insertAtFirst(head,10);
    cout<<"After Insertion at the beginning"<<endl;
    LinkedListTraversal(head);*/

    /*Insert in between
    head=insertAtIndex(head,10,2);
    cout<<"After Insertion at any Index"<<endl;
    LinkedListTraversal(head);*/

    /*Insert at the end
    head=insertAtEnd(head,10);
    cout<<"After Insertion at the end"<<endl;
    LinkedListTraversal(head);*/

    //Inset after a node
    head=insertAfterNode(head,third,10);
    cout<<"Insertion after a node"<<endl;
    LinkedListTraversal(head);


    return 0;
}

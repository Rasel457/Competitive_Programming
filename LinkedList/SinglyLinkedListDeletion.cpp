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
} ;

void LinkedListTraversal(Node *ptr)
{
    while(ptr!=NULL)
    {
        cout<<"Element : "<<ptr->data<<endl;
        ptr=ptr->next;
    }
}

Node *DeleteFirst(Node *head)
{
    Node *ptr=head;
    head=head->next;
    free(ptr);
    ptr=NULL;
    return head;
}

Node *DeleteAtIndex(Node *head,int index)
{
    Node *p=head;
    Node *q=head->next;

    for(int i=0;i<index-1;i++) //i=0 means 0 based Index
    {
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
    q=NULL;
    return head;


    /*Node *p=head;
    int i=0;// i=0 means 0 based index
    while(i!=index-1)
    {
        p=p->next;
        i++;
    }

    Node *q=p->next;
    p->next=q->next;
    free(q);
    q=NULL;
    return head;*/


}

Node *DeleteAtEnd(Node *head)
{
    Node *p=head;
    Node *q=head->next;

    while(q->next!=NULL)
    {
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    q=NULL;
    return head;

}

Node *DeleteGivenValue(Node *head,int value)
{
    Node *p=head;
    Node *q=head->next;

    while(q->data!=value && q->next!=NULL)
    {
        p=p->next;
        q=q->next;
    }
    if(q->data==value)
    {
        p->next=q->next;
        free(q);
        q=NULL;
    }

    return head;

}

Node *DeleteEntireList(Node *head)
{
    Node *ptr=head;

    while(ptr!=NULL)
    {
        ptr=ptr->next;
        free(head);
        head=ptr;
    }
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
    head->next=second;

    second->data=3;
    second->next=third;

    third->data=8;
    third->next=fourth;

    fourth->data=1;
    fourth->next=NULL;

    cout<<"Link List Before Deletion "<<endl;
    LinkedListTraversal(head);

    /*cout<<"After deleting the first node "<<endl;
    head=DeleteFirst(head);
    LinkedListTraversal(head);*/

    /*cout<<"After deleting at any index value"<<endl;
    head=DeleteAtIndex(head,2);
    LinkedListTraversal(head);*/

    /*cout<<"After deleting the last element"<<endl;
    head=DeleteAtEnd(head);
    LinkedListTraversal(head);*/

    cout<<"After deleting the given value"<<endl;
    head=DeleteGivenValue(head,8);
    LinkedListTraversal(head);

    /*cout<<"After deleting entire linked list"<<endl;
    head=DeleteEntireList(head);
    if(head==NULL)
    {
        cout<<"Linked List deleted successfully"<<endl;
    }*/

    return 0;
}

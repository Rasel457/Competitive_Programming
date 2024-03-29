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

struct node{
    int data;
    Node *left;
    Node *right;

    node(int d)
    {
        data=d;
        left=NULL;
        right=NULL;
    }
};

Node *BuildTree(Node *root)
{
    int val;
    cout<<"Enter a data : ";
    cin>>val;
    root=new node(val);

    if(val==-1)
    {
        return NULL;
    }
    cout<<"Enter data for inserting in left of "<<val<<endl;
    root->left=BuildTree(root->left);
    cout<<"Enter data for inserting in right of "<<val<<endl;
    root->right=BuildTree(root->right);

    return root;
}

void  InOrderTraversal(Node *temp)
{
    if(temp!=NULL)
    {
        InOrderTraversal(temp->left);
        cout<<temp->data<<" ";
        InOrderTraversal(temp->right);
    }
}

Node * InOrderPredecessor(Node *root)
{
    //cout<<"Here 2: "<<root->data<<endl;
    root=root->left;
    while(root->right!=NULL)
    {
        root=root->right;
    }
    return root;
}

Node * InOrderSuccessor(Node *root)
{
   // cout<<"Here 3: "<<root->data<<endl;
    root=root->right;
    while(root->left!=NULL)
    {
        root=root->left;
    }
    return root;
}

Node *DeleteNode(Node *root,int value)
{
    Node *Ipre;
    if(root==NULL)
    {
       //cout<<"Here 4"<<endl;
        return NULL;
    }
    //root->data==value condition for use when deleted elemrnt not in BST
    if(root->left==NULL && root->right==NULL && root->data==value)
    {
        //cout<<"Here 5"<<endl;
        free(root);
        return NULL;
    }
    if(root->data>value)
    {
        root->left=DeleteNode(root->left,value);
    }
    else if(root->data<value)
    {
        root->right=DeleteNode(root->right,value);
    }
    else
    {
        //cout<<"Here 1: "<<root->data<<endl;
        Node *p=root->left;
        if(p!=NULL)
        {
            Ipre=InOrderPredecessor(root);
            root->data=Ipre->data;
            root->left=DeleteNode(root->left,Ipre->data);
        }
        else
        {
            Ipre=InOrderSuccessor(root);
            root->data=Ipre->data;
            root->right=DeleteNode(root->right,Ipre->data);
        }

    }
    return root;
}
int main()
{
    //ios_base::sync_with_stdio(false);
   // cin.tie(NULL);
   // cout.tie(NULL);

    Node *root=NULL;
    root=BuildTree(root);
    cout<<endl;

    cout<<"InOrder traversal:"<<endl;
    InOrderTraversal(root);
    cout<<endl;

    int val;
    cout<<"Enter a value for delete: ";
    cin>>val;
    Node *p=DeleteNode(root,val);

    cout<<"InOrder traversal:"<<endl;
    InOrderTraversal(p);
    cout<<endl;





    return 0;
}

/*
9 4 2 -1 -1 7 5 -1 -1 8 -1 -1 11 -1 15 14 -1 -1 -1

5 3 1 -1 -1 4 -1 -1 6 -1 -1

1 -1 2 -1 -1
*/


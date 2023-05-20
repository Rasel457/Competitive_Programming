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
    Node *left;
    Node *right;

    node(int d)
    {
        data=d;
        left=NULL;
        right=NULL;
    }
} ;

Node *BuildTree(Node *root)
{
    int data;
    cout<<"Enter a value : ";
    cin>>data;
    root=new node(data);

    if(data==-1)
    {
        return NULL;
    }

    cout<<"Enter data for inserting in left of "<<data<<endl;
    root->left=BuildTree(root->left);
    cout<<"Enter data for inserting in right of "<<data<<endl;
    root->right=BuildTree(root->right);

    return root;
}

void InOrderTraversal(Node *temp)
{
    if(temp!=NULL)
    {
        InOrderTraversal(temp->left);
        cout<<temp->data<<" ";
        InOrderTraversal(temp->right);

    }
}

Node *Insert(Node *root, int key)
{
    Node *ptr=root;
    if(root==NULL)
    {
         //Node * newNode=(Node *)malloc(sizeof(Node));
         //newNode->data=key;
         //newNode->left=NULL;
         //newNode->right=NULL;
         Node * newNode=new node(key);
         return newNode;
    }
    Node *prev=NULL;

    while(root!=NULL)
    {
        prev=root;
        if(root->data==key)
        {
            cout<<"Can not Insert "<<key<<", already in BST"<<endl;
            return ptr;
        }
        else if(key<root->data)
        {
            root=root->left;
        }
        else
        {
            root=root->right;
        }
    }

    //Node * newNode=(Node *)malloc(sizeof(Node));
    Node * newNode=new node(key);
    if(key<prev->data)
    {
        //newNode->data=key;
       // newNode->left=NULL;
       // newNode->right=NULL;

        prev->left=newNode;

    }
    else
    {
         //newNode->data=key;
         //newNode->left=NULL;
         //newNode->right=NULL;

        prev->right=newNode;
    }
    return ptr;
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

    cout<<"Enter a data for Insert: ";
    int val;
    cin>>val;

    Node *p=Insert(root,val);

    cout<<"InOrder traversal after insertion:"<<endl;
    InOrderTraversal(p);
    cout<<endl;



    return 0;
}

/*
9 4 2 -1 -1 7 5 -1 -1 8 -1 -1 11 -1 15 14 -1 -1 -1
*/

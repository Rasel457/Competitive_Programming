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

int isBST(Node *root){
    static Node *prev = NULL;
    if(root!=NULL){
        if(!isBST(root->left))
        {
            return 0;
        }
        if(prev!=NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else{
        return 1;
    }
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

    int ans=isBST(root);
    if(ans==1)
    {
        cout<<"This is a BST"<<endl;
    }
    else
    {
        cout<<"This is not a BST"<<endl;
    }

    return 0;
}

/*
9 4 2 -1 -1 7 5 -1 -1 8 -1 -1 11 -1 15 14 -1 -1 -1
*/

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

    node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
} ;


Node *buildTree(Node *root)
{
    cout<<"Enter the value: ";
    int val;
    cin>>val;
    root=new node(val);

    if(val==-1)
    {
        return NULL;
    }

    cout<<"Enter data for inserting in left of "<<val<<endl;
    root->left=buildTree(root->left);
    cout<<"Enter data for inserting in right of "<<val<<endl;
    root->right=buildTree(root->right);
    return root;


}

void levelOrderTraversal(Node *root)
{
    vector<vector<int>>ans;
    queue<node*>q;
    q.push(root);

    while(!q.empty())
    {
        int sz=q.size();
        vector<int>l;
        for(int i=0;i<sz;i++)
        {
            Node *temp=q.front();
            q.pop();
            if(temp->left!=NULL)
            {
                q.push(temp->left);
            }
            if(temp->right!=NULL)
            {
                q.push(temp->right);
            }
            l.pb(temp->data);

        }
        ans.pb(l);

    }

    for(auto v:ans)
    {
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
}

/*void levelOrderTraversal(Node *root)
{
    queue<node*>q;
    q.push(root);

    while(!q.empty())
    {
        Node *temp=q.front();
        q.pop();
        cout<<temp->data<<" ";

        if(temp->left!=NULL)
        {
            q.push(temp->left);
        }
        if(temp->right!=NULL)
        {
            q.push(temp->right);
        }
    }
}*/

//Traverse Preorder (Root,Left,Right)
void traversePreOrder(Node *temp) {
  if(temp!=NULL)
  {
      cout<<temp->data<<" ";
      traversePreOrder(temp->left);
      traversePreOrder(temp->right);
  }
}

// Traverse Inorder(Left,Root,Right)
void traverseInOrder(Node *temp) {
  if (temp != NULL) {
    traverseInOrder(temp->left);
    cout <<temp->data<<" ";
    traverseInOrder(temp->right);
  }
}

// Traverse Postorder(Left,Right,Root)
void traversePostOrder(Node *temp) {
  if (temp != NULL) {
    traversePostOrder(temp->left);
    traversePostOrder(temp->right);
    cout<< temp->data<<" ";
  }
}
//Max Hight/Depth
int maxDepth(Node *temp)
{
    if(temp==NULL)
    {
        return 0;
    }
    int lh=maxDepth(temp->left);
    int rh=maxDepth(temp->right);

    return 1+max(lh,rh);
}

//Diameter
/*int maxi=-1;
int DiaMeter(Node *temp)//complexity: O(n*n)
{
    if(temp==NULL)
    {
        return 0;
    }
    int lh=maxDepth(temp->left);
    int rh=maxDepth(temp->right);
    maxi=max(maxi,lh+rh);
    DiaMeter(temp->left);
    DiaMeter(temp->right);

    return maxi;
}*/

int maxHeightForDiameter(Node *temp,int &diameter)
{
    if(temp==NULL)
    {
        return 0;
    }
    int lh=maxHeightForDiameter(temp->left,diameter);
    int rh=maxHeightForDiameter(temp->right,diameter);

    diameter=max(diameter,lh+rh);
    return 1+max(lh,rh);
}

int DiaMeter(Node *temp)
{
    int diameter=0;
    maxHeightForDiameter(temp,diameter);
    return diameter;

}
//Invert Binary Using Recursion
Node *InvertUsingRecursion(Node *temp)
{
    if(temp==NULL)
    {
        return NULL;
    }

    Node *left_child=InvertUsingRecursion(temp->left);
    Node *right_child=InvertUsingRecursion(temp->right);

    temp->left=right_child;
    temp->right=left_child;

    return temp;
}

//Invert Binary Using Level Order Traversal Technique 
Node *InvertUsingLOT(Node *root)
{
    if(root==NULL)
    {
        return NULL;
    }

    queue<node*>q;
    q.push(root);

    while(!q.empty())
    {
        Node *temp=q.front();
        q.pop();
        Node *p=temp->left;
        temp->left=temp->right;
        temp->right=p;

        if(temp->left!=NULL)
        {
            q.push(temp->left);
        }
        if(temp->right!=NULL)
        {
            q.push(temp->right);
        }
    }

    return root;
}


int main()
{
    /*ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Node *root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);

    cout << "preorder traversal: ";
    traversePreOrder(root);*/

    Node *root=NULL;
    root=buildTree(root);
    cout<<endl;

    cout<<"Level Order Traversal"<<endl;
    levelOrderTraversal(root);
    cout<<endl;

    cout<<"PreOrder Traversal"<<endl;
    traversePreOrder(root);
    cout<<endl;

    cout<<"InOrder Traversal"<<endl;
    traverseInOrder(root);
    cout<<endl;

    cout<<"PostOrder Traversal"<<endl;
    traversePostOrder(root);
    cout<<endl;

    int l=maxDepth(root);
    cout<<"Max Depth "<<l<<endl;


    int d=DiaMeter(root);
    cout<<"Diameter "<<d<<endl;

    Node * ptr=InvertUsingRecursion(root);

    cout<<"Level Order Traversal after Invert"<<endl;
    levelOrderTraversal(ptr);
    cout<<endl;

    /*Node * pt=InvertUsingLOT(root);

    cout<<"Level Order Traversal after Invert"<<endl;
    levelOrderTraversal(pt);
    cout<<endl;*/

    return 0;
}

/*
1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

1 2 -1 -1 3 4 5 -1 -1 -1 6 -1 -1

1 2 -1 -1 3 4 5 6 -1 -1 -1 -1 7 -1 8 -1 9 -1 -1
*/




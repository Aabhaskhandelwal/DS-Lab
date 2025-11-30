#include<iostream>
#include<queue>
#include<vector>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) 
    {
        data=val;
        left=nullptr;
        right=nullptr;
    }
};
int numTrees(int n) 
{
    if(n<0)
    return 0;

    vector<int> arr(n+1,0);
    arr[0]=1;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        arr[i]+=arr[j-1]*arr[i-j];
    }
    return arr[n];
}
vector<Node*> buildTrees(int st,int end)
{
    vector<Node*> ans;
    if(st>end)
    {
        ans.push_back(nullptr);
        return ans;
    }
    for(int i=st;i<=end;i++)
    {
        vector<Node*> leftTree=buildTrees(st,i-1);
        vector<Node*> rightTree=buildTrees(i+1,end);

        for(int k=0;k<leftTree.size();k++)
        {
            Node* left=leftTree[k];
            for(int j=0;j<rightTree.size();j++)
            {
                Node* right=rightTree[j];
                Node* root=new Node(i);
                root->left=left;
                root->right=right;
                ans.push_back(root);
            }
        }
    }
    return ans;
}
void nthEllements(Node* root, int level)
{
    if(root==nullptr)
    return;
        
    if(level==1)
    {
        cout<<root->data<<" ";
        return;
    }
    nthEllements(root->left, level-1);
    nthEllements(root->right, level-1);
}
int heightTree(Node* root)
{
    if (root==nullptr || root->left==nullptr && root->right==nullptr)
    return 0;           

    return (1+max(heightTree(root->left),heightTree(root->right)));
}
void print(Node* root) 
{
    if (root==nullptr) 
    {
        cout<<"null\n";
        return;
    }
    queue<Node*> q;
    q.push(root);

    vector<string> res;
    while (!q.empty()) 
    {
        Node* curr=q.front();
        q.pop();
        if (curr!=nullptr) 
        {
            res.push_back(to_string(curr->data));
            q.push(curr->left);
            q.push(curr->right);
        }
        else 
        res.push_back("null");
    }

    
    while (!res.empty() && res.back()=="null")
    res.pop_back();

    for (int i=0;i<res.size();i++)
    cout<<res[i]<<" ";

}
int main()
{
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;

    cout<<"Number of unique binary trees: "<<numTrees(n);
    
    vector<Node*> ans=buildTrees(1, n);
    cout<<"\nThese trees are:\n";
    for (int i=0;i<ans.size();i++) 
    {
        print(ans[i]);
        cout<<endl;
    }
    return 0;
}

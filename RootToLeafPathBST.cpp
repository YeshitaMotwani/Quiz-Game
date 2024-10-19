#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node* left,*right;
    Node(int data)
    {
        this->data=data;
        left=right=NULL;
    }
};
Node* insert(Node* root,int val)
{
    if(root==NULL){
        root=new Node(val);
        return root;
    }
    if(val<root->data)
    {
        root->left=insert(root->left,val);
    }
    else{
        root->right=insert(root->right,val);
    }
    return root;
}
void inorder(Node* root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
Node* buildBST(int arr[],int n)
{
    Node* root=NULL;
    for(int i=0;i<n;i++)
    {
        root=insert(root,arr[i]);
    }
    return root;
}
void printPath(vector<int> path)
{
    cout<<"\nPath:";
    for(int i=0;i<path.size();i++)
    {
        cout<<path[i]<<" ";
    }
    cout<<endl;
}
void pathHelper(Node* root,vector<int> &path)
{
    if(root==NULL)
        return;
    path.push_back(root->data);
    if(!root->left && !root->right) //root=> leaf node
    {
        printPath(path);
        path.pop_back();
        return; //backtrack
    } 
    pathHelper(root->left,path);
    pathHelper(root->right,path);
}
void rootToLeafPath(Node* root)
{
    vector<int> path;
    pathHelper(root,path);
}
int main(){
    int arr[6]={5,1,3,4,2,7};
    Node* root=buildBST(arr,6);
    inorder(root);
    rootToLeafPath(root);
    cout<<endl;

    return 0;
}
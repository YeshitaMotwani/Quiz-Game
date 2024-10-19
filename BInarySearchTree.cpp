#include<iostream>
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
bool search(Node* root,int key){
    if(root==NULL)
        return false;
    if(root->data==key)
        return true;
    if(key<root->data)
        return search(root->left,key);
    else
        return search(root->right,key);
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
Node* getInorderSuccessor(Node* root)
{
    while(root->left==NULL)
    {
        root=root->left;
    }
    return root; //IS
}
Node* delNode(Node* root,int val)
{
    if(root==NULL)  
        return NULL;
    //1. Searching node
    if(root->data>val) //left subtree
        root->left=delNode(root->left,val);
    else if(val>root->data) //right subtree
        root->right=delNode(root->right,val);
    else{
        //Case:root->data == val
        //3 sub cases
        //case 1: Node: 0 children => leaf node =>left and right child/subtree ==NULL
        if(root->left==NULL && root->right==NULL)
        {
            delete root;
            return NULL;
        }
        //Case 2:Node: 1 child
        if(!root->left || !root->right)
        {
            return root->left==NULL ? root->right : root->left;
        }
        //case 3: Node: 2 children
        Node* IS=getInorderSuccessor(root->right); //IS: right subtree -> leftmost node =IS
        root->data=IS->data;
        root->right=delNode(root->right,IS->data);
        return root;
    }
    return root;
}
int main(){
    int arr[6]={5,1,3,4,2,7};
    Node* root=buildBST(arr,6);
    inorder(root);
    cout<<endl;
    cout<<search(root,4)<<endl;
    delNode(root,4);
    inorder(root);
    cout<<endl;

    return 0;
}
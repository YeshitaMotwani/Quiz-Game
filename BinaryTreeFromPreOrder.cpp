#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data)
    {
        this->data=data;
        left=right=NULL;
    }
};
static int idx=-1;
Node* buildTree(vector<int> nodes)
{
    idx++; //move to next idx in preorder vector/array
    if(nodes[idx]==-1) //Base case
        return NULL;
    Node* currNode=new Node(nodes[idx]); //create a new node with value present in nodes vector at idx index
    currNode->left=buildTree(nodes); //left subtree
    currNode->right=buildTree(nodes); //right subtree
    return currNode;
}
void preOrder(Node* root)
{
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    preOrder(root->left); //left subtree
    preOrder(root->right); //right subtree
}
int main(){
    vector<int> nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1}; //preorder
    Node* root=buildTree(nodes);
    //cout<<"\nRoot:"<<root->data;
    cout<<"\nPreorder traversal:";
    preOrder(root);
    cout<<endl;
    return 0;
}
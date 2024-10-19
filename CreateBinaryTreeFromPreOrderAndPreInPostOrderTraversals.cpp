#include<iostream>
#include<vector>
#include<queue>
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
void inOrder(Node* root)
{
    if(root==NULL)
        return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
void postOrder(Node* root)
{
    if(root==NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}
void levelOrder(Node* root)
{
    if(root==NULL)
        return;
    queue<Node*> Q;
    Q.push(root);
    Q.push(NULL); //new line
    while(!Q.empty())
    {
        Node* curr=Q.front();
        Q.pop();
        if(curr==NULL)
        {
            cout<<"\n";
            if(Q.empty())
                break; //to avoid infinite loop when queue becomes empty and prevent from adding NULL again and again 
            Q.push(NULL); //to track new line
        }
        else{
            cout<<curr->data<<" ";
            if(curr->left!=NULL)
                Q.push(curr->left);
            if(curr->right!=NULL)
                Q.push(curr->right);
        }
    }
    cout<<endl;
}
int main(){
    vector<int> nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1}; //preorder
    Node* root=buildTree(nodes);
    //cout<<"\nRoot:"<<root->data;
    cout<<"\nPreorder traversal:";
    preOrder(root);
    cout<<endl;
    cout<<"\nInorder traversal:";
    inOrder(root);
    cout<<endl;
    cout<<"\nPostorder traversal:";
    postOrder(root);
    cout<<endl;
    cout<<"\nLevelorder traversal:"<<endl;
    levelOrder(root);
    cout<<endl;
    return 0;
}
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
static int idx=-1;
Node* buildTree(vector<int> nodes)
{
    idx++;
    if(nodes[idx]==-1) //NULL
        return NULL;
    Node* currNode=new Node(nodes[idx]);
    currNode->left=buildTree(nodes);
    currNode->left=buildTree(nodes);
    return currNode;
}
bool rootToNodePath(Node* root,int n,vector<int> &path)
{
    if(root==NULL)
        return false;
    path.push_back(root->data);
    if(root->data==n)
        return true;
    bool isLeft=rootToNodePath(root->left,n,path);
    bool isRight=rootToNodePath(root->right,n,path);
    if(isLeft || isRight)
        return true;
    path.pop_back();
    return false;
}
int LCA(Node* root,int n1,int n2)
{
    vector<int> path1;
    vector<int> path2;
    rootToNodePath(root,n1,path1);
    rootToNodePath(root,n2,path2);
    int lca=-1;
    for(int i=0,j=0;i<path1.size() && j<path2.size();i++,j++)
    {
        if(path1[i]!=path2[j])
            return lca;
        lca=path1[i];
    }
    return lca;
}
int main(){
    vector<int> nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1}; //preorder sequence
    Node* root=buildTree(nodes);
    cout<<"\nRoot:"<<root->data<<endl;
    int n1=5;
    int n2=6;
    cout<<"Lowest Common Ancestor:"<<LCA(root,n1,n2)<<endl;
    return 0;
}
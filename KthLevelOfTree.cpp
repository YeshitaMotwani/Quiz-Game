#include<iostream>
using namespace std;
#include<queue>
#include<vector>
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
    if(nodes[idx]==-1)
        return NULL;
    Node* currNode=new Node(nodes[idx]);
    currNode->left=buildTree(nodes); //left subtree
    currNode->right=buildTree(nodes); //right subtree
    return currNode;
}
/*
Iterative Approach - Level Order Traversal(BFS) T.C =O(n^2)
void levelOrder(Node* root, int K) {
    if (root == NULL)
        return;

    queue<Node*> Q;
    Q.push(root);
    int level = 0;

    while (!Q.empty()) {
        int levelSize = Q.size();

        for (int i =0; i < levelSize; ++i) {
            Node* curr = Q.front();
            Q.pop();

            if (level == K) {
                cout << curr->data << " ";
            }

            if (curr->left != NULL)
                Q.push(curr->left);
            if (curr->right != NULL)
                Q.push(curr->right);
        }

        if (level == K)
            break;
        
        level++;
    }
}*/
//Recursive Approach T.C = O(n)
void kthHelper(Node* root,int K, int currLevel)
{
    if(root==NULL)
        return;
    if(currLevel==K)
    {
        cout<<root->data<<" ";
        return;
    }
    kthHelper(root->left,K,currLevel+1);
    kthHelper(root->right,K,currLevel+1);
}
void levelOrder(Node* root,int K)
{
    kthHelper(root,K,1);
    cout<<endl;
}
int main(){
    vector<int> nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root=buildTree(nodes);
    cout<<"\nRoot:"<<root->data<<endl;
    int K;
    cout<<"\nEnter the value of K:";
    cin>>K;
    levelOrder(root,K);
}
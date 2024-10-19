#include <iostream>
using namespace std;

struct TreeNode {
    int value;
    TreeNode *left, *right;
    TreeNode(int data) : value(data), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
public:
    TreeNode* root;

    BinarySearchTree() : root(nullptr) {}

    void add(int value) {
        root = addRecursive(root, value);
    }

    TreeNode* addRecursive(TreeNode* root, int value) {
        if (root == nullptr) {
            return new TreeNode(value);
        }
        if (value < root->value) {
            root->left = addRecursive(root->left, value);
        } else if (value > root->value) {
            root->right = addRecursive(root->right, value);
        }
        return root;
    }

    void display() {
        displayRecursive(root);
    }

    void displayRecursive(TreeNode* root) {
        if (root != nullptr) {
            displayRecursive(root->left);
            cout << root->value << " ";
            displayRecursive(root->right);
        }
    }

    void remove(int value) {
        root = removeRecursive(root, value);
    }

    TreeNode* removeRecursive(TreeNode* root, int value) {
        if (root == nullptr) {
            return root;
        }
        if (value < root->value) {
            root->left = removeRecursive(root->left, value);
        } else if (value > root->value) {
            root->right = removeRecursive(root->right, value);
        } else {
            if (root->left == nullptr) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            TreeNode* temp = minValueNode(root->right);
            root->value = temp->value;
            root->right = removeRecursive(root->right, temp->value);
        }
        return root;
    }

    TreeNode* minValueNode(TreeNode* node) {
        TreeNode* current = node;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
    }
};

int main() {
    BinarySearchTree tree;
    tree.add(50);
    tree.add(30);
    tree.add(20);
    tree.add(40);
    tree.add(70);
    tree.add(60);
    tree.add(80);

    cout << "Binary Search Tree: ";
    tree.display();
    cout << endl;

    cout << "Removing 20: ";
    tree.remove(20);
    tree.display();
    cout << endl;

    cout << "Removing 30: ";
    tree.remove(30);
    tree.display();
    cout << endl;

    cout << "Removing 50: ";
    tree.remove(50);
    tree.display();
    cout << endl;

    return 0;
}
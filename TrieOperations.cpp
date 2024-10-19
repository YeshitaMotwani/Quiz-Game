#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
using namespace std;

class Node {
public:
    unordered_map<char, Node*> children;    
    bool endOfWord;
    Node() {
        endOfWord = false;
    }
};

class Trie {
    Node* root;
public:
    Trie() {
        root = new Node(); //No data in root node of Trie
    }
    void insert(string key) {
        Node* temp = root;
        for (int i = 0; i < key.size(); i++) {
            if (temp->children.count(key[i]) == 0) { // Does not exist
                temp->children[key[i]] = new Node(); // Create a new node
            }
            temp = temp->children[key[i]]; // Level update
        }
        temp->endOfWord = true;
    }
    bool search(string key) {
        Node* temp = root;
        for (int i = 0; i < key.size(); i++) {
            if (temp->children.count(key[i])) {
                temp = temp->children[key[i]]; // Level update
            }
            else {
                return false;
            }
        }
        return temp->endOfWord; // Return true if endOfWord == true
    }
};
int main() {
    vector<string> words = {"the", "a", "there", "any", "their", "thee"};
    Trie trie;
    for (int i = 0; i < words.size(); i++) {
        trie.insert(words[i]);
    }
    cout << trie.search("their") << endl; // Should output 1 (true)
    return 0;
}

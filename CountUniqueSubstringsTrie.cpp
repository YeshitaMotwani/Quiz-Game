#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
using namespace std;

class Node {
public:
    unordered_map<char, Node*> children;
    bool endOfWord;
    int freq;
    Node() {
        endOfWord = false;
    }
};

class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
        root->freq = -1;
    }
    void insert(string key) {
        Node* temp = root;
        for (int i = 0; i < key.size(); i++) {
            if (temp->children.count(key[i]) == 0) { // Does not exist
                temp->children[key[i]] = new Node(); // Create a new node
                temp->children[key[i]]->freq = 1;
            }
            else{
                temp->children[key[i]]->freq++;
                }
            temp = temp->children[key[i]]; // Level update
        }
        temp->endOfWord = true;
    }
    int countHelper()
};
void buildTrieFromSuffix(string key){
        Trie trie;
        for(int i=0;i<key.size();i++){
            trie.insert(key.substr(i));
        }
}
    int count(Node* root){
        int ans=0;
        Node* temp=root;
        for(auto &child:root->children[i]){
            ans += count(temp->children[i]);
        }
        return ans+1;
}
int main(){
    Trie trie;
    trie.count(root)<<endl;
    return 0;
}
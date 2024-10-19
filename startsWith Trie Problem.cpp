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
    bool startsWith(string key){
        Node* temp=root;
        for(int i=0;i<key.size();i++){
            if(temp->children[key[i]])
                temp=temp->children[key[i]];
            else
                return false;
        }
        return true;
    }
};
int main(){
    Trie trie;
    vector<string> dict={"apple","app","mango","man","woman"};
    for(int i=0;i<dict.size();i++){
        trie.insert(dict[i]);
    }
    cout<<trie.startsWith("app")<<endl;
    return 0;
}
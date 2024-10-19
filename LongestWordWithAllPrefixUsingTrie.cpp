#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
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
        root = new Node();
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
            } else {
                return false;
            }
        }
        return temp->endOfWord; // Return true if endOfWord == true
    }

    string longestHelper(Node* root, string &ans, string temp) {
        // Accessing all children of curr Node
        for (auto &child : root->children) {
            // Each letter of child Node -> endOfWord == true
            if (child.second->endOfWord == true) {
                temp += child.first;
                if ((temp.size() == ans.size() && temp < ans) || temp.size() > ans.size()) {
                    // If size of temp and ans are equal, then select Lexicographically smallest string
                    // otherwise select longest possible string(size)
                    ans = temp;
                }
                longestHelper(child.second, ans, temp);
                temp.pop_back();
            }
        }
        return ans;
    }

    string longestStringWithEOW() {
        string ans = "";
        return longestHelper(root, ans, "");
    }
};

string longestString(vector<string> dict) {
    Trie trie;
    for (int i = 0; i < dict.size(); i++) {
        trie.insert(dict[i]);
    }
    return trie.longestStringWithEOW();
}

int main() {
    vector<string> dict = {"a", "banana", "app", "appl", "ap", "apply", "apple"};
    cout << longestString(dict) << endl;
    return 0;
}

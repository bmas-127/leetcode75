#include <iostream>
#include <string>

using namespace std;

class Trie {
    struct Node{
        string text;
        Node *left, *right;

        Node(string t){
            text = t;
            left = nullptr;
            right = nullptr;
        }
    };

    Node *root;
public:
    Trie() {
        root = nullptr;
    }
    
    void insert(string word) {
        if (root == nullptr){
            root = new Node(word);
        }else{
            Node *cur = root;
            while(true){
                if(word < cur->text){
                    if(cur->left == nullptr){
                        cur->left = new Node(word);
                        break;
                    }
                    cur = cur->left;
                }else{
                    if(cur->right == nullptr){
                        cur->right = new Node(word);
                        break;
                    }
                    cur = cur->right;
                }
            
            }
        }
    }
    
    bool search(string word) {
        Node *cur = root;
        while(cur != nullptr){
            if(word < cur->text){
                cur = cur->left;
            }else if(word > cur->text){
                cur = cur->right;
            }else{
                return true;
            }
        }

        return false;
    }
    
    bool startsWith(string prefix) {
        Node *cur = root;
        while(cur != nullptr){
            if(cur->text.compare(0, prefix.length(), prefix)){
                return true;
            }else if(prefix < cur->text){
                cur = cur->left;
            }else{
                cur = cur->right;
            }
        }
        
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
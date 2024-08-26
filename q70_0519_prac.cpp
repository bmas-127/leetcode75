#include <iostream>
#include <string>

using namespace std;

class bst{
    struct node
    {
        int val;
        node *left, *right;

        node(int a){
            val = a;
        }
    };

    node* head;
    
public:
    bst(){
        head = nullptr;
    }

    void insert(int num){
        node* new_node = new node(num);

        if(head == nullptr){
            head = new_node;
        }else{
            node* cur = head;
            while(true){
                cout << cur->val << endl;
                if(num <= cur->val){
                    if(cur->left == nullptr){
                        cur->left = new_node;
                        break;
                    }
                    cur = cur->left;
                }else{
                    if(cur->right == nullptr){
                        cur->right = new_node;
                        break;
                    }
                    cur = cur->right;
                }
            }
        }
    }

    void traverse(){
        inorder(head);
        cout << endl;
    }

    void inorder(node* n){
        if(n != nullptr){
            inorder(n->left);
            cout << n->val << ' ';
            inorder(n->right);
        }
    }

};

int main(){
    bst b;

    b.insert(4);
    b.insert(7);
    b.insert(5);
    b.insert(6);
    b.insert(3);
    b.insert(2);
    b.insert(8);
    b.insert(1);

    b.traverse();

    string a = "abc";
    string c = "efghi";

    cout << (a < c) << endl;

    return 0;
}
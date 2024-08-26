#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    bool found;
    TreeNode* exact_node;
    int val;
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        found = false;
        exact_node = nullptr;
        this->val = val;

        traverse(root);

        return exact_node;
    }

    void traverse(TreeNode* root){
        if(!found && root != nullptr){
            if(root->val == val){
                found = true;
                exact_node = root;
            }
            traverse(root->left);
            traverse(root->right);
        }
    }
};
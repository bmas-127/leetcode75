#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
        std::vector<int> ra;
public:
    std::vector<int> rightSideView(TreeNode* root) {
        traverse(root, 0);
        return ra;
    }

    void traverse(TreeNode* root, int level){
        if(root != nullptr){
            traverse(root->left, level + 1);
            if(level >= ra.size()){
                ra.resize(level+1);
            }
            ra[level] = root->val;
            traverse(root->right, level + 1);
        }
    }
};
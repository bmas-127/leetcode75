#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int max;
public:
    int maxDepth(TreeNode* root) {
        max = 0;
        search(root, 1);
    }

    void search(TreeNode* root, int level){
        if(root != nullptr){
            max = std::max(max, level);
            search(root->left, level + 1);
            search(root->right, level + 1);
        }
    }
};
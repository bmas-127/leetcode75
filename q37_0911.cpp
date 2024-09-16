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
    int maxZigZag;
public:
    int longestZigZag(TreeNode* root) {
        maxZigZag = 0;
        traverse(root->left, 1, 0);
        traverse(root->right, 1, 1);

        return maxZigZag;
    }

    void traverse(TreeNode* root, int curDepth, bool dir){
        if(root == nullptr){
            // total count depth
            maxZigZag = std::max(curDepth, maxZigZag);
        }else{
            if(dir){
                traverse(root->left, curDepth + 1, !dir);
                traverse(root->right, 0, dir);
            }else{
                traverse(root->right, curDepth + 1, !dir);
                traverse(root->left, 0, dir);
            }
        }

    }
};
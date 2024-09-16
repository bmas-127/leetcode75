
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int goodNums = 0;
public:
    int goodNodes(TreeNode* root) {
        countGoodNodes(root, -10000000);
        
        return goodNums;
    }

    void countGoodNodes(TreeNode* root, int curMaxVal){
        if(root != nullptr){
            if(root->val >= curMaxVal){
                goodNums ++;
                curMaxVal = root->val;
            }
            countGoodNodes(root->left, curMaxVal);
            countGoodNodes(root->right, curMaxVal);
        }
    }
};
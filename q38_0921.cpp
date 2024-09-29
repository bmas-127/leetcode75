struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    TreeNode* LCA;
    bool LCAFound;
    bool num1Found;
    bool num2Found;
    int num1; 
    int num2;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        num1Found = num2Found = LCAFound = false;
        num1 = p->val;
        num2 = q->val;

        traverse(root);

        return LCA;
    }

    void traverse(TreeNode* root){
        if(root != nullptr && !LCAFound){
            traverse(root->left);

            bool tmpNum1Found = num1Found;
            bool tmpNum2Found = num2Found;
            num1Found = false;
            num2Found = false;

            traverse(root->right);

            if(root->val == num1){
                num1Found = true;
            }else if(root->val == num2){
                num2Found = true;
            }

            num1Found = num1Found || tmpNum1Found;
            num2Found = num2Found || tmpNum2Found;

            if(num1Found && num2Found && !LCAFound){
                LCA = root;
                LCAFound = true;
            }
        }
    }
};
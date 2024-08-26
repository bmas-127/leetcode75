#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
    int global_sum;
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return 0;

        // check it self
        global_sum = 0;
        pathSumStartHead(root, targetSum, 0);
        int ans = global_sum;

        if(root->left != nullptr){
            ans += pathSum(root->left, targetSum);
        }
        
        if(root->right != nullptr){
            ans += pathSum(root->right, targetSum);
        }

        return ans;        
    }

    void pathSumStartHead(TreeNode* root, int targetSum, long int currentSum){
        currentSum += root->val;
        if(currentSum == targetSum){
            global_sum += 1;
        }
        if(root->left != nullptr){
            pathSumStartHead(root->left, targetSum, currentSum);
        }
        if(root->right != nullptr){
            pathSumStartHead(root->right, targetSum, currentSum);
        }
    }
};

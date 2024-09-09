
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    TreeNode* parent;
    TreeNode* deleteTreeNode;
    TreeNode* rightLeastNode;
    TreeNode* rightLeastParent;
    TreeNode** parentLink;
    int key;
    int found = 0;
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode *dummy_head = new TreeNode(key+1, root, nullptr);
        this->key = key;

        searchNode(dummy_head);

        if(deleteTreeNode == nullptr){
            return root;
        }
        
        rightLeastParent = deleteTreeNode;
        searchRightLeastParent(deleteTreeNode->right);

        if(!rightLeastNode){
            *parentLink = deleteTreeNode->left;
        }else if(rightLeastNode == deleteTreeNode->right){
            *parentLink = rightLeastNode;
            rightLeastNode->left = deleteTreeNode->left;
        }else{
            *parentLink = rightLeastNode;
            rightLeastParent->left = rightLeastNode->right;
            rightLeastNode->left = deleteTreeNode->left;
            rightLeastNode->right = deleteTreeNode->right;
        }

        return dummy_head->left;
    }

    void searchRightLeastParent(TreeNode* root){
        if(root != nullptr){
            rightLeastNode = root;
            while(rightLeastNode->left){
                rightLeastParent = rightLeastNode;
                rightLeastNode = rightLeastNode->left;
            }
        }
    }
    
    
    void searchNode(TreeNode* root){
        if(root == nullptr || parentLink){
            return;
        }else if(root->left != nullptr && root->left->val == key){
            parent = root;
            deleteTreeNode = root->left;
            parentLink = &root->left;
        }else if(root->right != nullptr && root->right->val == key){
            parent = root;
            deleteTreeNode = root->right;
            parentLink = &root->right;
        }

        searchNode(root->left);
        searchNode(root->right);
    }
};
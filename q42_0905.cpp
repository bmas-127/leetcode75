
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
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* dummyHead = new TreeNode(key+1, root, nullptr);

        searchNode(dummyHead, key);

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

        return dummyHead->left;
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

    
    void searchNode(TreeNode* root, int key){
        parent = root;
        root = root->left;
        while(root != nullptr){
            if(root->val == key){
                deleteTreeNode = root;
                if(parent->val > key){
                    parentLink = &parent->left;
                }else{
                    parentLink = &parent->right;
                }
                break;
            }else{
                parent = root;
                if(root->val > key){
                    root = root->right;
                }else{
                    root = root->left;
                }
            }

        }
    }

};
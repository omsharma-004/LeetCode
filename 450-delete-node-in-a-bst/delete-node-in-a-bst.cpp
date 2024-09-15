class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            return nullptr;
        }
        
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            if (root->left == nullptr) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            TreeNode* maxLeft = root->left;
            while (maxLeft->right != nullptr) {
                maxLeft = maxLeft->right;
            }
            root->val = maxLeft->val;
            root->left = deleteNode(root->left, maxLeft->val);
        }
        
        return root;
    }
};
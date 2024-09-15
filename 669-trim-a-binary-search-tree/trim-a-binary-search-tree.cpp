class Solution {
public:
    void helper(TreeNode* root, int low, int high){
        if(root==NULL) return;
        while(root->left!=NULL){
            if(root->left->val < low){
                root->left=root->left->right;
            }
            else if(root->left->val > high){
                root->left=root->left->left;
            }
            else break;
        }
        while(root->right!=NULL){
            if(root->right->val > high){
                root->right=root->right->left;
            }
            else if(root->right->val < low){
                root->right=root->right->right;
            }
            else break;
        }
        helper(root->left, low, high);
        helper(root->right, low, high);
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        TreeNode* temp=new TreeNode(INT_MAX);
        temp->left=root;
        helper(temp, low, high);
        return temp->left;
    }
};
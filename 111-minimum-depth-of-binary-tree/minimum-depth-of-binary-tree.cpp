class Solution {
public:
    int helper(TreeNode* root){
        if(root==NULL) return 0;
        if(root->left==NULL) return 1+helper(root->right);
        if(root->right==NULL) return 1+helper(root->left);
        return 1+min(helper(root->left),helper(root->right));
    }
    int minDepth(TreeNode* root) {
        return helper(root);
    }
};
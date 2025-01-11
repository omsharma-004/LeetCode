class Solution {
public:
    int count=0;
    int helper(TreeNode* root){
        if(root!=NULL) count++;
        if(root->left!=NULL) helper(root->left);
        if(root->right!=NULL) helper(root->right);
        return count;
    }
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        return helper(root);
    }
};
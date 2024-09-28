class Solution {
public:
    int helper(TreeNode *root, int& result) {
        if (root==NULL) return 0;
        int l=max(0,helper(root->left, result));
        int r=max(0,helper(root->right, result));
        result=max(result, l+r+root->val);
        return root->val + max(l, r);
    }
    int maxPathSum(TreeNode *root) {
        int result=INT_MIN;
        helper(root, result);
        return result;
    }
};
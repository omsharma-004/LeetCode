class Solution {
public:
    int helper(TreeNode* root, int ans, int cur){
        if(root==NULL) return 0;
        int r=0;
        if(root->val>=cur){
            r=1;
            cur=root->val;
        }
        int left=helper(root->left, ans, cur);
        int right=helper(root->right, ans, cur);
        return left+right+r;
    }
    int goodNodes(TreeNode* root) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        return helper(root, 0, INT_MIN);
    }
};
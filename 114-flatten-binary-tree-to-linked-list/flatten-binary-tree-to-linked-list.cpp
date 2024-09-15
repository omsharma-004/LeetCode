class Solution {
public:
    void helper(TreeNode* root, vector<TreeNode*>& ans){
        if(root==NULL) return;
        ans.push_back(root);
        helper(root->left, ans);
        helper(root->right, ans);
    }
    void flatten(TreeNode* root) {
        vector<TreeNode*> ans;
        helper(root,ans);
        int n=ans.size();
        for(int i=0;i<n-1;i++){
            ans[i]->right=ans[i+1];
            ans[i]->left=NULL;
        }
    }
};
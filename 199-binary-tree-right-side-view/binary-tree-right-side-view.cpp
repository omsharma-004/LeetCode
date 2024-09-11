class Solution {
public:
    int levels(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(levels(root->left),levels(root->right));
    }
    void nlevel(TreeNode* root, int curr, int level, vector<int>& ans){
        if(root==NULL) return;
        if(curr==level){
            ans[curr]=root->val;
            return;
        }
        nlevel(root->left, curr+1, level, ans);
        nlevel(root->right, curr+1, level, ans);
    }
    void norder(TreeNode* root, vector<int>& ans){
        int n=ans.size();
        for(int i=0;i<n;i++){
            nlevel(root, 0, i, ans);
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans(levels(root),0);
        norder(root, ans);
        return ans;
    }
};
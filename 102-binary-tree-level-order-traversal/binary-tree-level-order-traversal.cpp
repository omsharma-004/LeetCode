/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int level(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(level(root->left), level(root->right));
    }
    void helper(TreeNode* root, int curr, int lvl, vector<int>& v){
        if(root==NULL) return;
        if(curr==lvl){
            v.push_back(root->val);
            return;
        }
        helper(root->left, curr+1, lvl, v);
        helper(root->right, curr+1, lvl, v);
    }
    void norder(TreeNode* root, vector<vector<int>>& ans){
        int n=level(root);
        for(int i=1;i<=n;i++){
            vector<int> v;
            helper(root, 1, i, v);
            ans.push_back(v);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        norder(root, ans);
        return ans;
    }
};
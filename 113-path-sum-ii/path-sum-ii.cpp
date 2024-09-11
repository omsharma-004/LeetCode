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
    void helper(TreeNode* root, vector<int>s, vector<vector<int>>& ans, int sum){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            if(root->val==sum){
                    s.push_back(root->val);
                ans.push_back(s); 
            }
            return;   
        }
        s.push_back(root->val);
        helper(root->left, s, ans, sum-(root->val));
        helper(root->right, s, ans, sum-(root->val));
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> v;
        helper(root, v, ans, targetSum);
        return ans;
    }
};
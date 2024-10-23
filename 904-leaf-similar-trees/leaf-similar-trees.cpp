class Solution {
public:
    void helper(TreeNode* root1, vector<int> &ans){
        if(root1==NULL) return ;
        if(root1->left==NULL && root1->right==NULL) ans.push_back(root1->val);
        helper(root1->left, ans);
        helper(root1->right, ans);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> ans1;
        vector<int> ans2;
        helper(root1, ans1);
        helper(root2, ans2);
        if(ans1.size()!=ans2.size()) return false;
        for(int i=0;i<ans1.size();i++){
            if(ans1[i]!=ans2[i]) return false;
        }
        return true;
    }
};
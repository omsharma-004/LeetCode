class Solution {
public:
    int helper(TreeNode* root, string a){
        if(root==NULL) return 0;
        a+=to_string(root->val);
        if(root->left==NULL && root->right==NULL) return stoi(a);
        return helper(root->left, a)+helper(root->right, a);
        
    }
    int sumNumbers(TreeNode* root) {
        return helper(root,"");
    }
};
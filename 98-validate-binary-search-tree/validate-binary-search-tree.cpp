class Solution {
public:
    long long minbst(TreeNode* root){
        if(root==NULL) return LLONG_MAX;
        else return min((long long)(root->val),min(minbst(root->left),minbst(root->right)));
    }
    long long maxbst(TreeNode* root){
        if(root==NULL) return LLONG_MIN;
        else return max((long long)(root->val),max(maxbst(root->left),maxbst(root->right)));
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return true;
        else if((long long)(root->val) >= minbst(root->right)) return false;
        else if((long long)(root->val) <= maxbst(root->left)) return false;
        return isValidBST(root->left) && isValidBST(root->right);
    }
};
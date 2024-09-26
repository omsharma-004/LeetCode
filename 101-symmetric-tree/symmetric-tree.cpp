class Solution {
private:
    bool helper(TreeNode* p, TreeNode* q){
        if(!p and !q) return true;
        if(!p or !q) return false;
        return p->val==q->val && helper(p->left, q->right) && helper(p->right, q->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return helper(root, root);
    }
};
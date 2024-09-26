class Solution {
private:
    bool helper(TreeNode* p, TreeNode* q){
        if(p==NULL && q==NULL) return true;
        if(p==NULL || q==NULL) return false;
        return p->val==q->val && helper(p->left, q->right) && helper(p->right, q->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return helper(root, root);
    }
};
class Solution {
public:
    int count=0;
    void helper(TreeNode* root, int steps, bool val){
        if(root==NULL) return;
        count=max(count,steps);
        if(val==true){
            helper(root->left, steps+1, false);
            helper(root->right, 1, true);
        }
        else{
            helper(root->right, steps+1, true);
            helper(root->left, 1, false);
        }
    }
    int longestZigZag(TreeNode* root) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        helper(root, 0, true);
        helper(root, 0, false);      
        return count;
    }
};
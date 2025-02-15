/**
 * Definition for a binary tree TreeNode.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* n1, TreeNode* n2) {
        while (root && (root->val > max(n1->val, n2->val) || root->val < min(n1->val, n2->val)))
            root = (root->val > n1->val) ? root->left : root->right;
        return root;
    }
};
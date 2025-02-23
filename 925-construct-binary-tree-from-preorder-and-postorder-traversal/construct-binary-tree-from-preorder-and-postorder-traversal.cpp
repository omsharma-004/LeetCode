/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* helper(vector<int>& preorder, vector<int>& postorder, int& a, int& b) {
        if (a >= preorder.size() || b >= postorder.size())
            return NULL;
        TreeNode* temp = new TreeNode(preorder[a]);
        a += 1;
        if (temp->val == postorder[b]) {
            b += 1;
            return temp;
        }
        temp->left = helper(preorder, postorder, a, b);
        if (temp->val == postorder[b]) {
            b += 1;
            return temp;
        }
        temp->right = helper(preorder, postorder, a, b);
        b += 1;
        return temp;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int a = 0, b = 0;
        return helper(preorder, postorder, a, b);
    }
};
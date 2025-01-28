class Solution {
public:
    vector<int> travel(TreeNode* root) {
        if (root == NULL)
            return {0, 0};
        vector<int> left = travel(root->left);
        vector<int> right = travel(root->right);
        vector<int> v(2);
        v[0] = root->val + left[1] + right[1];
        v[1] = max(left[0], left[1]) + max(right[0], right[1]);
        return v;
    }
    int rob(TreeNode* root) {
        vector<int> res = travel(root);
        return max(res[0], res[1]);
    }
};
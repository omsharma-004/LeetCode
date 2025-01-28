class Solution {
public:
    int solve(TreeNode* root, map<TreeNode*, int>& map) {
        if (root == nullptr) {
            return 0;
        }

        if (map.find(root) != map.end()) {
            return map[root];
        }

        int profit = 0;
        if (root->left != nullptr) {
            profit +=
                solve(root->left->left, map) + solve(root->left->right, map);
        }

        if (root->right != nullptr) {
            profit +=
                solve(root->right->left, map) + solve(root->right->right, map);
        }

        profit = max(profit + root->val,
                     solve(root->left, map) + solve(root->right, map));

        return map[root] = profit;
    }
    int rob(TreeNode* root) {
        map<TreeNode*, int> map;
        return solve(root, map);
    }
};
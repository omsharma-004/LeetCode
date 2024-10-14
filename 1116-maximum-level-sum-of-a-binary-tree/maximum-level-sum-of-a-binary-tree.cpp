class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        if (root == NULL) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int maxSum = INT_MIN;
        int maxLevel = 0;
        int currentLevel = 0;
        while (!q.empty()) {
            int levelSize = q.size();
            currentLevel++;
            int currentLevelSum = 0;
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                currentLevelSum += node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            if (currentLevelSum > maxSum) {
                maxSum = currentLevelSum;
                maxLevel = currentLevel;
            }
        }

        return maxLevel;
    }
};
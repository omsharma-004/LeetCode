class Solution {
public:
    std::vector<int> largestValues(TreeNode* root) {
        if (!root) return {};
        vector<int> v;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int curr_level_size = q.size();
            int val = INT_MIN;
            for (int i = 0; i < curr_level_size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                val = max(val, node->val);
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            v.push_back(val);
        }
        
        return v;
    }
};
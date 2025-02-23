class Solution {
private:
    TreeNode* helper(vector<int>& pre, vector<int>& post, int preStart,
                     int postStart, int length,
                     unordered_map<int, int>& postIndexMap) {
        if (length == 0)
            return nullptr;
        TreeNode* root = new TreeNode(pre[preStart]);
        if (length == 1)
            return root;
        int leftChildValue = pre[preStart + 1];
        int leftChildIndexInPost = postIndexMap[leftChildValue];
        int leftSubtreeSize = leftChildIndexInPost - postStart + 1;
        root->left = helper(pre, post, preStart + 1, postStart, leftSubtreeSize,
                            postIndexMap);
        root->right = helper(pre, post, preStart + 1 + leftSubtreeSize,
                             postStart + leftSubtreeSize,
                             length - 1 - leftSubtreeSize, postIndexMap);

        return root;
    }

public:
    TreeNode* constructFromPrePost(vector<int>& preorder,
                                   vector<int>& postorder) {
        unordered_map<int, int> postIndexMap;
        for (int i = 0; i < postorder.size(); i++) {
            postIndexMap[postorder[i]] = i;
        }
        return helper(preorder, postorder, 0, 0, preorder.size(), postIndexMap);
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class FindElements {
public:
    TreeNode* root_;
    FindElements(TreeNode* root) {
        root_ = root;
    }
    
    bool find(int target) {
        std::vector<bool> directions; // false means left true means right
        int depth = 0;
        int pow_2 = 1;
        int current = 0;
        while (target > current) {
            pow_2 *= 2;
            current += pow_2;
            ++depth;
        }
        
        target -= pow_2 - 1;
        while (depth > 0) {
            directions.push_back(int(target % 2 == 1));
            target /= 2;
            --depth;
        }

        TreeNode* current_node = root_;
        int i = directions.size() - 1;
        while (current_node && i >= 0) {
            bool right = directions[i];
            if (right) {
                current_node = current_node->right;
            } else {
                current_node = current_node->left;
            }
            --i;
        }
        return bool(current_node);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
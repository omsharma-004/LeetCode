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
class Solution {
public:
int id = 0;
TreeNode* helper(string traversal, int depth){
    if(id == traversal.size()) return NULL;

    int idx = id;
    int cnt = 0;
    while(idx < traversal.size() && traversal[idx] == '-'){
        cnt++;
        idx++;
    }
    
    if(cnt != depth) return NULL;

    string temp = "";
    while(idx < traversal.size() && traversal[idx] != '-'){
        temp += traversal[idx];
        idx++;
    }

    id = idx;
    TreeNode *root = new TreeNode(stoi(temp));

    root->left = helper(traversal, depth + 1);
    root->right = helper(traversal, depth + 1);

    return root;
}

    TreeNode* recoverFromPreorder(string traversal) {
        return helper(traversal, 0);
    }
};
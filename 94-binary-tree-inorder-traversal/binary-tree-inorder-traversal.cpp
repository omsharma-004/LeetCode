// class Solution {
// public:
// void helper(TreeNode* root, vector<int>& ans){
//         if(root==NULL) return;
//         helper(root->left, ans);
//         ans.push_back(root->val);
//         helper(root->right, ans);
//     }
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> ans;
//         helper(root, ans);
//         return ans;
//     }
// };

// Iterative solution
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* node=root;
        while(st.size()>0 || node!=NULL){
            if(node!=NULL){
                st.push(node);
                node=node->left;
            }
            else{
                TreeNode* temp=st.top();
                st.pop();
                ans.push_back(temp->val);
                node=temp->right;
            }
        }
        return ans;
    }
};
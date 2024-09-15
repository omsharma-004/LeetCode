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
// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> ans;
//         stack<TreeNode*> st;
//         TreeNode* node=root;
//         while(st.size()>0 || node!=NULL){
//             if(node!=NULL){
//                 st.push(node);
//                 node=node->left;
//             }
//             else{
//                 TreeNode* temp=st.top();
//                 st.pop();
//                 ans.push_back(temp->val);
//                 node=temp->right;
//             }
//         }
//         return ans;
//     }
// };

//MORRIS TRAVERSAL
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr= root;
        while(curr!=NULL){
            if(curr->left!=NULL){
                TreeNode* pre=curr->left;
                while(pre->right!=NULL && pre->right!=curr){
                    pre=pre->right;
                }
                if(pre->right==NULL){
                    pre->right=curr;
                    curr= curr->left;
                }
                else{
                    pre->right=NULL;
                    ans.push_back(curr->val);
                    curr=curr->right;
                }
            }
            else{
                ans.push_back(curr->val);
                curr=curr->right;
            }
        }
        return ans;
    }
};
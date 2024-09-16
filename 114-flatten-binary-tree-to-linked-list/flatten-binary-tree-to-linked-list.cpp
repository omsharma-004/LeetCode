// class Solution {
// public:
//     void helper(TreeNode* root, vector<TreeNode*>& ans){
//         if(root==NULL) return;
//         ans.push_back(root);
//         helper(root->left, ans);
//         helper(root->right, ans);
//     }
//     void flatten(TreeNode* root) {
//         vector<TreeNode*> ans;
//         helper(root,ans);
//         int n=ans.size();
//         for(int i=0;i<n-1;i++){
//             ans[i]->right=ans[i+1];
//             ans[i]->left=NULL;
//         }
//     }
// };

//O(N) space
// class Solution {
// public:
//     void flatten(TreeNode* root) {
//         if(root==NULL) return;
//         TreeNode* l=root->left;
//         TreeNode* r=root->right;
//         root->left=NULL;
//         root->right=NULL;
//         flatten(l);
//         flatten(r);
//         TreeNode* temp=root;
//         root->right=l;
//         while(temp->right!=NULL){
//             temp=temp->right;
//         }
//         temp->right=r;
//     }
// };

//Moriis 

class Solution {
public:
    void flatten(TreeNode* root) {
        if(root==NULL) return;
        TreeNode* curr=root;
        while(curr!=NULL){
            if(curr->left!=NULL){
                TreeNode* r=curr->right;
                curr->right=curr->left;
                TreeNode* pred=curr->left;
                while(pred->right!=NULL) pred=pred->right;
                pred->right=r;
                curr=curr->left;
            }
            else{
                curr=curr->right;
            }
        }
        TreeNode* temp=root;
        while(temp->right!=NULL){
            temp->left=NULL;
            temp=temp->right;
        }
    }
};
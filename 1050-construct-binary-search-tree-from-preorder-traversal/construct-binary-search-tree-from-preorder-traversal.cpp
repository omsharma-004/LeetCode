// class Solution {
// public:
//     TreeNode* build(vector<int>& pre, int prelo, int prehi, vector<int>& in, int inlo, int inhi){
//         if(prelo>prehi) return NULL;
//         TreeNode* root= new TreeNode(pre[prelo]);
//         if(prelo==prehi) return root;
//         int i=inlo;
//         while(i<inhi){
//             if(in[i]==pre[prelo]) break;
//             i++;
//         }
//         int leftcount=i-inlo;
//         root->left=build(pre, prelo+1, prelo+leftcount, in, inlo, i-1);
//         root->right=build(pre, prelo+leftcount+1, prehi, in, i+1, inhi);
//         return root;
//     }
//     TreeNode* bstFromPreorder(vector<int>& preorder) {
//         vector<int> help=preorder;
//         sort(help.begin(), help.end());
//         int n=preorder.size();
//         return build(preorder, 0, n-1, help, 0, n-1);
//     }
// };

//using insertion for loop
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL) return new TreeNode(val);
        else if(root->val>val){
            if(root->left==NULL){
                root->left=new TreeNode(val);
            }
            else insertIntoBST(root->left, val);
        }
        else{
            if(root->right==NULL){
                root->right=new TreeNode(val);
            }
            else insertIntoBST(root->right, val);
        }  
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root=new TreeNode(preorder[0]);
        for(int i=1;i<preorder.size();i++){
            insertIntoBST(root,preorder[i]);
        }
        return root;
    }
};
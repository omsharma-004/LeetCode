class Solution {
public:
    TreeNode* build(vector<int>& in, int inlo, int inhi, vector<int>& post, int plo, int phi){
        if(plo>phi) return NULL;
        TreeNode* root= new TreeNode(post[phi]);
        if(plo==phi) return root;
        int i=inlo;
        while(i<=inhi){
            if(in[i]==post[phi]) break;
            i++;
        }
        int rightcount=inhi-i;
        root->left=build(in, inlo, i-1, post, plo, phi-rightcount-1);
        root->right=build(in, i+1, inhi, post, phi-rightcount, phi-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=postorder.size();
        return build(inorder, 0, n-1, postorder, 0, n-1);
    }
};
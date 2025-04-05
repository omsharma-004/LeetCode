class Solution {
public:
bool helper(TreeNode* root , set<int>&st,int target)
    {
        if(root == nullptr) return false;      
        int value=(target - root->val);      
        if(st.count(value))
        {
            return true;
        }    
        st.insert(root->val);
        return helper(root->left,st,target)  || helper(root->right,st,target);   
    }
    bool findTarget(TreeNode* root, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
         set<int>st;
        return helper(root,st,k);
    }
};

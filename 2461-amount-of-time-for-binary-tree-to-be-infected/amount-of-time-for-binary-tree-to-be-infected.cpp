class Solution {
public:
    TreeNode* first=NULL;
    void find(TreeNode* root, int start){
        if(root==NULL) return;
        if(root->val==start){
            first=root;
            return;
        }
        find(root->left, start);
        find(root->right, start);
    }
    void parent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& mp){
        if(root==NULL) return;
        if(root->left!=NULL) mp[root->left]=root;
        if(root->right!=NULL) mp[root->right]=root;
        parent(root->left, mp);
        parent(root->right, mp);
    }
    int amountOfTime(TreeNode* root, int start) {
        find(root, start);
        unordered_map<TreeNode*, TreeNode*> mp;
        parent(root, mp);
        unordered_set<TreeNode*> s;
        s.insert(first);
        queue<pair<TreeNode*, int>> q;
        q.push({first, 0});
        int maxlevel=INT_MIN;
        while(q.size()>0){
            pair<TreeNode*, int> p=q.front();
            q.pop();
            int level=p.second;
            maxlevel=max(maxlevel, level);
            TreeNode* temp=p.first;
            if(temp->left){
                if(s.find(temp->left)==s.end()){
                    q.push({temp->left, level+1});
                    s.insert(temp->left);
                }
            }
            if(temp->right){
                if(s.find(temp->right)==s.end()){
                    q.push({temp->right, level+1});
                    s.insert(temp->right);
                }
            }
            if(mp.find(temp)!=mp.end()){
                if(s.find(mp[temp])==s.end()){
                    q.push({mp[temp], level+1});
                    s.insert(mp[temp]);
                }
            }
        }
        return maxlevel;
    }
};
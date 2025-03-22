class Solution {
public:
    void dfs(int u,vector<bool>& vis,unordered_map<int,vector<int>>& adj,int &vt,int &ed){
        vis[u]=true;
        vt++;
        ed+=adj[u].size();
        for(int &v:adj[u]){
            if(vis[v]) continue;
            dfs(v,vis,adj,vt,ed);
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>adj;
        for(auto &x:edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        int res=0;
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                int vt=0,ed=0;
                dfs(i,vis,adj,vt,ed);
                ed/=2;
                if(ed==(vt*(vt-1)/2)) res++;
            }
        }
        return res;
    }
};
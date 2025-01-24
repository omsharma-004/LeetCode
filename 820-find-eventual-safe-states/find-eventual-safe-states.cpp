class Solution {
public:
    void dfs(int node, vector<vector<int>>& graph, vector<int>& vis, vector<int>& is_safe, int parent) {
        vis[node] = 1;
        bool ans = 1;
        for (auto x : graph[node]) {
            if (!vis[x]) {
                dfs(x, graph, vis, is_safe, node);
                ans &= is_safe[x];
            } else {
                ans &= is_safe[x];
            }
        }
        is_safe[node] = ans;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<int> ans;
        int n = graph.size();
        vector<int> vis(n, 0);
        vector<int> is_safe(n, 0);
        
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, graph, vis, is_safe, -1);
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (is_safe[i]) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

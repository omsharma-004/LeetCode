class Solution {
public:
    int findRoot(vector<int>& groups, int i) {
        if (groups[i] != i) {
            groups[i] = findRoot(groups, groups[i]);
        }
        return groups[i];
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> groups(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            groups[i] = i;
        }
        for (int i = 0; i < n; i++) {
            int root1 = findRoot(groups, edges[i][0]), root2 = findRoot(groups, edges[i][1]);
            if (root1 == root2) {
                return edges[i];
            }
            if (root2 < root1) {
                int tmp = root1;
                root1 = root2;
                root2 = tmp;
            }
            groups[root2] = root1;
        }
        return {0, 0};
    }
};
class Solution {
public:

    int dirX[4] = {0, +0, 1, -1};
    int dirY[4] = {1, -1, 0, +0};

    int n, m;
    vector<vector<int>> v;

    int dfs(int x, int y) {
        if (x < 0 || x >= n || y < 0 || y >= m || v[x][y] == 0)
            return 0;

        int sum = v[x][y];
        v[x][y] = 0;
        for (int i = 0; i < 4; ++i) {
            sum += dfs(x + dirX[i], y + dirY[i]);
        }
        return sum;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        v = grid;

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ans = max(ans, dfs(i, j));
            }
        }
        return ans;
    }
};
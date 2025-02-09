class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        dp[n - 1][m - 1] = max(1, 1 - grid[n - 1][m - 1]);
        for (int j = m - 2; j >= 0; j--) {
            dp[n - 1][j] = max(1, dp[n - 1][j + 1] - grid[n - 1][j]);
        }
        for (int i = n - 2; i >= 0; i--) {
            dp[i][m - 1] = max(1, dp[i + 1][m - 1] - grid[i][m - 1]);
        }
        for (int i = n - 2; i >= 0; i--) {
            for (int j = m - 2; j >= 0; j--) {
                dp[i][j] = min(max(1, dp[i + 1][j] - grid[i][j]),
                               max(1, dp[i][j + 1] - grid[i][j]));
            }
        }
        return dp[0][0];
    }
};

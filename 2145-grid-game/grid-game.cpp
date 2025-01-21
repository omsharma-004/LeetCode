class Solution {
 public:
  long long gridGame(vector<vector<int>>& grid) {
    const int n = grid[0].size();
    long ans = LONG_MAX;
    long r0 = accumulate(grid[0].begin(), grid[0].end(), 0L);
    long r1 = 0;
    for (int i = 0; i < n; ++i) {
      r0 -= grid[0][i];
      ans = min(ans, max(r0, r1));
      r1 += grid[1][i];
    }
    return ans;
  }
};
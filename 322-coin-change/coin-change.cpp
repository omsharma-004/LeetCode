class Solution {
public:
    int coinChange(vector<int>& coins, int n) {
        vector<int> dp(n + 1, n + 1);
        dp[0] = 0;
        for (int i : coins) {
            for (int j = i; j <= n; j++) {
                dp[j] = min(dp[j], dp[j - i] + 1);
            }
        }
        if (dp[n] == n + 1)
            return -1;
        return dp[n];
    }
};
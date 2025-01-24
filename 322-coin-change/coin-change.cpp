class Solution {
public:
    int helper(int n, vector<int>& dp, vector<int>& coins) {
        if (n == 0)
            return 0;
        if (n < 0)
            return INT_MAX;
        if (dp[n] != -1)
            return dp[n];
        int minc = INT_MAX;
        for (auto i : coins) {
            if (n - i >= 0) {
                int temp = helper(n - i, dp, coins);
                if (temp != INT_MAX)
                    minc = min(minc, temp);
            }
        }
        if (minc == INT_MAX)
            dp[n] = INT_MAX;
        else
            dp[n] = minc + 1;
        return dp[n];
    }
    int coinChange(vector<int>& coins, int n) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<int> dp(n + 1, -1);
        int a = helper(n, dp, coins);
        if (a == INT_MAX)
            return -1;
        return a;
    }
};
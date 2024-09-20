class Solution {
public:
    int climbStairs(int n) {
        vector<int> memo(n + 1, -1);
        return climbStairsRecursive(n, memo);
    }
    int climbStairsRecursive(int n, vector<int>& memo) {
        if (n <= 1) return 1;    
        if (memo[n] != -1) {
            return memo[n];
        }
        memo[n] = climbStairsRecursive(n - 1, memo) + climbStairsRecursive(n - 2, memo);
        return memo[n];
    }
};

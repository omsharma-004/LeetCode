class Solution {
public:
    int helper(int n, vector<int>& dp){
        if(n==0) return 0;
        if(dp[n]!=-1) return dp[n];
        int minsq=INT_MAX;
        for(int i=1;i*i<=n;i++){
            minsq=min(minsq,helper(n-i*i,dp));
        }
        dp[n]=minsq+1;
        return dp[n];
    }
    int numSquares(int n) {
        vector<int> dp(n+1,-1);
        return helper(n, dp);
    }
};
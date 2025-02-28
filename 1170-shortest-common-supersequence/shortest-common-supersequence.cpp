class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n = str1.size();
        int m = str2.size();
        
        // Step 1: Compute the Longest Common Subsequence (LCS) DP table
        vector<vector<int>> memo(n + 1, vector<int>(m + 1, 0));
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (str1[i - 1] == str2[j - 1]) 
                    memo[i][j] = 1 + memo[i - 1][j - 1];
                else 
                    memo[i][j] = max(memo[i - 1][j], memo[i][j - 1]);
            }
        }
        
        // Step 2: Backtrack to construct the Shortest Common Supersequence
        string ans = "";
        int i = n, j = m;
        
        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                ans.push_back(str1[i - 1]);
                i--;
                j--;
            } else if (memo[i - 1][j] >= memo[i][j - 1]) {
                ans.push_back(str1[i - 1]);
                i--;
            } else {
                ans.push_back(str2[j - 1]);
                j--;
            }
        }
        
        // Add remaining characters from str1 and str2
        while (i > 0) {
            ans.push_back(str1[i - 1]);
            i--;
        }
        while (j > 0) {
            ans.push_back(str2[j - 1]);
            j--;
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
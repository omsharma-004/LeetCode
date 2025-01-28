class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> v(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            v[i] = v[i - 1] + arr[i - 1];
        }
        int ans = 0;
        for (int i = 0; i <= k; i++) {
            int score = v[i] + (v[n] - v[n - (k - i)]);
            ans = max(ans, score);
        }
        return ans;
    }
};

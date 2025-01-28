class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int left = 0;
        int right = 0;
        int ans = 0;
        for (int i = 0; i < k; i++) {
            left += arr[i];
        }
        ans = left;
        int r = arr.size() - 1;
        for (int i = k - 1; i >= 0; i--) {
            left = left - arr[i];
            right += arr[r];
            r--;

            ans = max(ans, left + right);
        }
        return ans;
    }
};
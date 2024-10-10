class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n = nums.size();
        stack<int> indices;
        for (int i = 0; i < n; ++i) {
            if (indices.empty() || nums[i] < nums[indices.top()]) {
                indices.push(i);
            }
        }
        int maxWidth = 0;
        for (int j = n - 1; j >= 0; --j) {
            while (!indices.empty() && nums[indices.top()] <= nums[j]) {
                int i = indices.top();
                indices.pop();
                maxWidth = max(maxWidth, j - i);
            }
        }
        return maxWidth;
    }
};
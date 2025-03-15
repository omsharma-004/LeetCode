class Solution {
public:
    int helper(const vector<int>& nums, int capacity) {
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i)
            if (nums[i] <= capacity) {
                ans++;
                i++;
            }
        return ans;
    }
    int minCapability(vector<int>& nums, int k) {
        int l = ranges::min(nums);
        int r = ranges::max(nums);
        while (l < r) {
            const int m = (l + r) / 2;
            if (helper(nums, m) >= k)
                r = m;
            else
                l = m + 1;
        }
        return l;
    }
};
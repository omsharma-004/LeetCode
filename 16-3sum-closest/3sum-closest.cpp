class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int minDiff = INT_MAX;
        int closest;
        for (int i = 0; i < n; ++i) {
            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target) {
                    return sum;
                } else if (sum < target) {
                    ++j;
                } else {
                    --k;
                }
                int diff = abs(sum - target);
                if (diff < minDiff) {
                    closest = sum;
                    minDiff = diff;
                }
            }
        }
        return closest;
    }
};
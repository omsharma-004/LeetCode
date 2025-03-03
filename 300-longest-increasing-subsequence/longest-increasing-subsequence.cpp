class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<int> dp;
        for (int num : nums) {
            auto it = lower_bound(dp.begin(), dp.end(), num);
            if (it == dp.end())
                dp.push_back(num);
            else
                *it = num;
        }
        return dp.size();
    }
};
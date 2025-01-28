class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        mp[0] = 1;
        int prefixSum = 0;
        int count = 0;
        for (int i = 0; i < n; i++) {
            prefixSum += nums[i];
            int mod = ((prefixSum % k) + k) % k;
            if (mp.find(mod) != mp.end()) {
                count += mp[mod];
            }
            mp[mod]++;
        }
        return count;
    }
};

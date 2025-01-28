class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int ans = 0;
        int sum = 0;
        mp[0] = 0;
        for (auto i : nums) {
            sum += i;
            int target = ((sum % k) + k) % k;
            if (mp.find(target) != mp.end()) {
                ans += mp[target] + 1;
                mp[target]++;
            } else {
                mp[target] = 0;
            }
        }
        return ans;
    }
};
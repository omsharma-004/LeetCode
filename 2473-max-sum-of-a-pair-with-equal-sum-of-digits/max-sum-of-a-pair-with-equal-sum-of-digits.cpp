class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = -1;
        for (int i : nums) {
            int dsum = 0;
            int num = i;
            while (num > 0) {
                dsum += num % 10;
                num = num / 10;
            }
            if (mp.find(dsum) != mp.end()) {
                ans = max(ans, mp[dsum] + i);
                if (i > mp[dsum]) {
                    mp[dsum] = i;
                }
                continue;
            }
            mp[dsum] = i;
        }
        return ans;
    }
};
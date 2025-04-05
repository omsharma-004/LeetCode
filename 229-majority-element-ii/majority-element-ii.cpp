class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n = nums.size();
        unordered_map<int, int> mp;
        vector<int> v;
        for (int i : nums)
            mp[i]++;
        for (auto it : mp) {
            if (it.second > n / 3)
                v.push_back(it.first);
        }
        return v;
    }
};
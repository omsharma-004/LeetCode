class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<int> v;
        unordered_map<int, int> mp;
        for (auto i : nums) {
            mp[i]++;
        }
        for (auto i : mp) {
            if (i.second > 1)
                v.push_back(i.first);
        }
        return v;
    }
};
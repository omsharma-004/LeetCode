class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n = nums.size();
        unordered_map<int, int> mp;
        vector<int> ans;
        for (int &x : nums) mp[x]++;
        vector<vector<int>> arr(n + 1);
        for (auto [a, b] : mp) arr[b].push_back(a);
        for (int i = n; i > 0; i--) {
            for (int &x : arr[i]) {
                if (ans.size() == k) return ans;
                ans.push_back(x);
            }
        }
        return ans;
    }
};
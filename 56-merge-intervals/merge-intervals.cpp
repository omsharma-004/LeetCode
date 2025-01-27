class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        for (auto it : intervals) {
            if (ans.empty() || ans.back()[1] < it[0]) {
                ans.push_back(it);
            } else {
                ans.back()[1] = max(it[1], ans.back()[1]);
            }
        }
        return ans;
    }
};
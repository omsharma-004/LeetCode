class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<pair<int, int>> copy;
        for (int i = 0; i < nums.size(); i++) {
            copy.push_back({nums[i], i});
        }
        sort(copy.begin(), copy.end());
        int left = 0, right = 1;
        while (left < right && right < nums.size()) {
            vector<int> ind = {copy[left].second};
            while (right < nums.size() &&
                   (copy[right].first - copy[right - 1].first) <= limit) {
                ind.push_back(copy[right].second);
                right++;
            }
            sort(ind.begin(), ind.end());
            for (int i = 0; i < right - left; i++) {
                nums[ind[i]] = copy[left + i].first;
            }
            left = right;
            right++;
        }
        return nums;
    }
};
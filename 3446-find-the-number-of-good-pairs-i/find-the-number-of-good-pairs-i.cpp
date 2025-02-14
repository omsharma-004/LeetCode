class Solution {
public:
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        unordered_map<int, int> mp;
        for (const auto& n : nums2) {
            mp[n * k]++;
        }

        int goodPair = 0;
        for (int n : nums1) {
            for (const auto& [d, c] : mp) {
                if (n % d == 0)
                    goodPair += c;
            }
        }
        return goodPair;
    }
};
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans;
        unordered_set<int> mp1(nums1.begin(),nums1.end());
        unordered_set<int> mp2(nums2.begin(),nums2.end());
        vector<int> v1,v2;
        for (const auto& num : mp1) {
            if (mp2.find(num) == mp2.end()) {
                v1.push_back(num);
            }
        }
        for (const auto& num : mp2) {
            if (mp1.find(num) == mp1.end()) {
                v2.push_back(num);
            }
        }
        ans.push_back(v1);
        ans.push_back(v2);
        return ans;
    }
};
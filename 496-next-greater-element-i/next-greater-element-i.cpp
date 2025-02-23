class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int m = nums2.size();
        vector<int> ans;
        unordered_map<int, int> mp;
        stack<int> st;
        for (int i = m - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }
            if (st.empty()) {
                mp[nums2[i]] = -1;
            } else {
                mp[nums2[i]] = st.top();
            }
            st.push(nums2[i]);
        }
        for (auto num : nums1) {
            ans.push_back(mp[num]);
        }
        return ans;
    }
};
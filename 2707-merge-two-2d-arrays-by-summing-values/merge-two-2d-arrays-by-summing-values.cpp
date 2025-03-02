class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int left = 0, right = 0;
        vector<vector<int>> res;
        
        while (left < nums1.size() && right < nums2.size()){
            if (nums1[left][0] == nums2[right][0]){
                res.push_back({nums1[left][0], nums1[left][1] + nums2[right][1]});
                left++;
                right++;
            } else if (nums1[left][0] < nums2[right][0]){
                res.push_back(nums1[left]);
                left++;
            } else {
                res.push_back(nums2[right]);
                right++;
            }
        }
        while (left < nums1.size()){
            res.push_back(nums1[left]);
            left++;
        }
        while (right < nums2.size()){
            res.push_back(nums2[right]);
            right++;
        }
        return res;
    }
};

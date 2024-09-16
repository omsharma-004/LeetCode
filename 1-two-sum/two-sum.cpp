// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//     for (int i = 0; i < nums.size(); i++) {
//         for (int j < nums. j = i + 1;size(); j++) {
//             if (nums[i] + nums[j] == target) {
//                 return {i, j};
//             }
//         }
//     }
//     return {};
//     }
// };

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int tar=target-nums[i];
            if(mp.find(tar)!=mp.end()){
                ans.push_back(mp[tar]);
                ans.push_back(i);
            }
            else mp[nums[i]]=i;
        }
        return ans;
    }
};
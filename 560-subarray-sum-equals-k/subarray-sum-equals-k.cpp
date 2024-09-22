// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         int n = nums.size();
//         int count = 0;
//         for (int i = 0; i < n; i++) {
//             int currentSum = 0;
//             for (int j = i; j < n; j++) {
//                 currentSum += nums[j];
//                 if (currentSum == k) {
//                     ++count;
//                 }
//             }
//         }
//         return count;
//     }
// };

//Using unordered map

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=1;i<n;i++){
            nums[i]+=nums[i-1];
        }
        int count=0;
        unordered_map<int ,int> mp;
        for(int i=0;i<n;i++){
            if(nums[i]==k){
                count++;
            }
            int rem=nums[i]-k;
            if(mp.find(rem)!=mp.end()) count+=mp[rem];
            mp[nums[i]]++;
        }
        return count;
    }
};
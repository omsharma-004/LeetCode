class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int pre=0;
        unordered_map<int, int> mp;
        mp[0]=-1;
        for(int i=0;i<nums.size();i++){
            pre+=nums[i];
            int rem=pre%k;
            if(mp.find(rem)!=mp.end()){
                if (i-mp[rem]>1) {
                    return true;
                }
            }
           else{
                mp[rem]=i;
            }
        }
        return false;
    }
};
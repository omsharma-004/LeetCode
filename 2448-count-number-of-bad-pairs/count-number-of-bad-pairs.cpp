class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
    long long ans =0 ;
    map<int,int>mp;
    for(int i =0  ; i<nums.size();i++){
        nums[i] = nums[i]-i;
        mp[nums[i]]++;
    }
    for(int i=0;i<nums.size();i++){
        ans+= nums.size()-i-1-mp[nums[i]] +1;
        mp[nums[i]] -=1;
    }
  return ans;


    }
};
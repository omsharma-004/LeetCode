class Solution {
public:
    int rev(int n){
        int i=0;
        while(n>0){
            i*=10;
            i+=(n%10);
            n/=10;
        }
        return i;
    }
    int countNicePairs(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            nums[i]-=rev(nums[i]);
        }
        unordered_map<int, int> mp;
        for(auto ele : nums){
            if(mp.find(ele)!=mp.end()){
                count %=1000000007;
                count+=mp[ele];
                mp[ele]++;
            }
            else mp[ele]++;
        }
        return count%1000000007;
    }
};
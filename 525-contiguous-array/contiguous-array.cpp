class Solution {
public:
    int findMaxLength(vector<int>& nums) {
       int cnt = 0;
       int ans = 0, n = nums.size();
       unordered_map<int,int>count_mp;
       for(int i=0;i<n;i++){
           int val = 0;
           if(nums[i] == 0)cnt--;
           if(nums[i] == 1)cnt++;
           if(cnt == 0)val = i+1;
           else if(count_mp.find(cnt) == count_mp.end()){
                count_mp[cnt] = i;
           }else{
               val = i - count_mp[cnt];
           }
           ans = max(ans,val);
       }
       return ans;
    }
};
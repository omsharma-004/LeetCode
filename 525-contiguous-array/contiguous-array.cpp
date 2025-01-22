class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
       int cnt = 0;
       int ans = 0;
       int n = nums.size();
       unordered_map<int,int>mp;
       for(int i=0;i<n;i++){
           int val = 0;
           if(nums[i] == 0)cnt--;
           if(nums[i] == 1)cnt++;
           if(cnt == 0)val = i+1;
           else if(mp.find(cnt) == mp.end()){
                mp[cnt] = i;
           }else{
               val = i - mp[cnt];
           }
           ans = max(ans,val);
       }
       return ans;
    }
};
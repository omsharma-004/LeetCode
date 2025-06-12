class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int res=0;
        for(int i=0;i<nums.size();i++){
            int a=(i+1)%nums.size();
            int b=abs(nums[i]-nums[a]);
            res=max(res,b);
        }
        return res;
    }
};
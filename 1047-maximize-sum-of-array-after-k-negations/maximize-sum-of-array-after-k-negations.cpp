class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        sort(nums.begin(), nums.end());
        while(k>0){
            nums[0]=-nums[0];
            sort(nums.begin(), nums.end());
            k--;
        }
        int sum=0;
        for(int i=0;i<nums.size();i++) sum+=nums[i];
        return sum;
    }
};
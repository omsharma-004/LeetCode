class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        sort(nums.begin(), nums.end());
        int l=0;
        int r=nums.size()-1;
        int count=0;
        while(l<r){
            if(nums[l]+nums[r]==k){
                l++;
                r--;
                count++;
            }
            else if(nums[l]+nums[r]<k){
                l++;
            }
            else{
                r--;
            }
        }
        return count;
    }
};
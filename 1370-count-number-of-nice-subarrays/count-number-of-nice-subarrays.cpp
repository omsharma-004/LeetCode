class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int result =0;
        int count =0;
        for(int l=0 ,r=0;r<nums.size();r++){
            if(nums[r]%2 ==1 ){
                count =0;
                k--;
            }
            while(k==0){
                count++;
                k +=nums[l++]%2;
            }
            result +=count;
        }
        return result;
    }
};
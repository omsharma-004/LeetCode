class Solution {
public:
    int rev(int n){
        int temp=0;
        while(n>0){
            temp*=10;
            temp+=(n%10);
            n/=10;
        }
        return temp;
    }
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> us;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int r=rev(nums[i]);
            nums.push_back(r);
        }
        for(int i=0;i<nums.size();i++){
            us.insert(nums[i]);
        }
        return us.size();
    }
};
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int one=0,temp_one=0;
        for(auto &x:nums){
            temp_one+=x;
            if(temp_one<0) temp_one=0;
            // cout<<temp_one<<" ";
            one=max(one,temp_one);
            // cout<<one<<endl;
        }
        for(auto &x:nums) x*=-1;
         int two=0,temp_two=0;
        for(auto &x:nums){
            temp_two+=x;
            if(temp_two<0) temp_two=0;
            two=max(two,temp_two);
        }
        return max(one,two);
    }
};
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
       unordered_map<int ,int>mpp;
       int count=0;
        for(auto it:nums){
            mpp[it]++;
        }
        for(auto m:mpp){
            count+=((m.second)*(m.second-1))/2;

        }
        return count;
    }
};
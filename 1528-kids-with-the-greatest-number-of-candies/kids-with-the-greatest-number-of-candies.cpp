class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int k) {
        int a=INT_MIN;
        vector<bool> ans;
        for(int i=0;i<candies.size();i++){
            a=max(candies[i],a);
        }
        for(int i=0;i<candies.size();i++){
            ans.push_back(candies[i]+k >= a);
        }
        return ans;
    }
};
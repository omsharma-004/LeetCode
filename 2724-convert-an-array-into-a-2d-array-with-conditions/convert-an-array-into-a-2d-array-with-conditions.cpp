class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int> fr;
        for(auto i:nums){
            fr[i]++;
        }
        int size = 0;
        
        for(auto i:fr) size = max(size,i.second);
        
        vector<vector<int>> res(size); 
        
        for(auto i:fr){
            for(int j = 0;j<i.second;j++){
                res[j].push_back(i.first);
            }
        }
        return res;
    }
};
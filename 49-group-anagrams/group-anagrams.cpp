class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;
        for(auto i:strs){
            string lexo=i;
            sort(lexo.begin(), lexo.end());
            if(mp.find(lexo)==mp.end()){
                vector<string> v;
                v.push_back(i);
                mp[lexo]=v;
            }
            else{
                mp[lexo].push_back(i);
            }
        }
        for(auto i : mp){
            vector<string> v=i.second;
            ans.push_back(v);
        }
        return ans;
    }
};
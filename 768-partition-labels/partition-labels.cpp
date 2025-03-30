class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>ans;
        unordered_map<char,int>map;
        for(int i=0;i<s.size();i++){
            map[s[i]]=i;
        }
        int maxindex=0;
        int j=0;
        for(int i=0;i<s.size();i++){
            maxindex=max(maxindex,map[s[i]]);
            if(i==maxindex){
                ans.push_back(i-j+1);
                j=i+1;
            }
        }
        return ans;
    }
};
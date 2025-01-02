class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> ans;
        vector<int> res;
        int c=0;
        auto isv=[](char c){
            return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
        };
        for(auto& i:words){
            if(isv(i[0]) && isv(i.back())){
                c++;
            }
            ans.push_back(c);
        }
        for(auto& i:queries){
            int a=i[0];
            int b=i[1];
            if(a==0){
                res.push_back(ans[b]);
            }
            else{
                res.push_back(ans[b] - ans[a-1]);
            }
        }
        return res;
    }
};
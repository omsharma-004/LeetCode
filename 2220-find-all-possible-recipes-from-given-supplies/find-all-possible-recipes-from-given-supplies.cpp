class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        vector<string> ans; unordered_map<string,int>mp;
        unordered_set<string>st; int n=recipes.size();

        for(int i=0; i<supplies.size(); i++){
            mp[supplies[i]]=1;
        }

        while(n>0){
            for(int i=0; i<recipes.size(); i++){
                int cnt=0;
                for(int j=0; j<ingredients[i].size(); j++){
                    if(mp[ingredients[i][j]]==1)cnt++;
                    else break;
                }
                if(cnt==ingredients[i].size()){
                    st.insert(recipes[i]);
                    mp[recipes[i]]=1;
                }
            }
            if(st.size()==recipes.size()) break;
            n--;
        }
        
        for(auto& it: st) ans.push_back(it);
        return ans;
        
        
        
    }
};
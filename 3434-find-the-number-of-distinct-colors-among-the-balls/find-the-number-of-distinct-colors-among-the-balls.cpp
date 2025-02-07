class Solution {
public:
    vector<int> queryResults(int lim, vector<vector<int>>& v) {
        int n=v.size();
        map<int,int>m; 
        map<int,int>col;
        map<int,bool>vis;
        vector<int>ans;
        for(int i=0;i<n;++i){
            int x=v[i][0],y=v[i][1];
            if(vis[x]){
                if(m[col[x]]){
                    m[col[x]]--;
                    if(m[col[x]]==0)m.erase(col[x]); 
                    cout<<"yahia"<<endl; 
                }
                m[y]++;
                col[x]=y; 
                ans.push_back(m.size());
                continue;
            }
            m[y]++;
            vis[x]=true;
            col[x]=y;
            ans.push_back(m.size());
        }
        return ans; 
    }
};
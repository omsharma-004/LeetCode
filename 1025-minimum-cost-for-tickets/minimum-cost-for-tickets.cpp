class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_map<int,int> mp;
        mp[1] = costs[0];
        mp[7] = costs[1];
        mp[30] = costs[2];
        
        vector<int> v(366, INT_MAX);
        v[0] = 0;
        for(int i=1; i<366; ++i){
            if(find(days.begin(), days.end(), i) == days.end()){
                v[i] = v[i-1];
                continue;
            }
            for(auto a : mp){
                v[i] = min(v[i], v[max(0, i-a.first)] + a.second);
            }
        }
        
        return v[365];
    }
};
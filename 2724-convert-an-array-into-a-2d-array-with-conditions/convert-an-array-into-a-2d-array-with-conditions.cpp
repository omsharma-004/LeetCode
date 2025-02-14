class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        unordered_map<int, int> m;
        int maxfreq = INT_MIN;
        for(auto n:nums){
            m[n]++;
            maxfreq = max(maxfreq, m[n]);
        }
        vector<vector<int>> ans(maxfreq);
        for(auto c:m){
            int num=c.first;
            int freq=c.second;
            while(freq){
                ans[--freq].push_back(num);
            }
        }
        return ans;

    }
};
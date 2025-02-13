class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        unordered_map<int,int> mp;
        long long width = 0;
        for(int i = 0; i < wall[0].size(); ++i) {
            width += wall[0][i];
        }
        for(auto& row : wall) {
            long long sum = 0;
            for(int i = 0; i < row.size() - 1; ++i) {
                sum += row[i];
                mp[sum]++;
            }
        }

        int maxEdges = 0;
        for(auto& [pos, count] : mp) {
            maxEdges = max(maxEdges, count);
        }
        return wall.size() - maxEdges;
    }
};
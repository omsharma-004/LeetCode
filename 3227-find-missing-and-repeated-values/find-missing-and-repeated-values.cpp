class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n = grid.size();
        int N = n * n;
        unordered_map<int, int> mp;

        for (auto &vec : grid) {
            for (int &i : vec) mp[i]++;
        }

        int x = -1, y = -1;
        for (int num = 1; num <= N; num++) {
            if (!mp.count(num)) x = num;  // Missing number
            else if (mp[num] > 1) y = num;  // Repeated number
            if (x != -1 && y != -1) break;
        }

        return {y, x};
    }
};
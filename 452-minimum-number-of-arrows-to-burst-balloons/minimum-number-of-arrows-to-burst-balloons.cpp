class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& arr) {
        if (arr.empty()) return 0;
        sort(arr.begin(), arr.end());
        int arrows = 1;
        int prevEnd = arr[0][1];
        for (int i = 1; i < arr.size(); ++i) {
            if (arr[i][0] > prevEnd) {
                arrows++;
                prevEnd = arr[i][1];
            } else {
                prevEnd = min(prevEnd, arr[i][1]);
            }
        }
        return arrows;
    }
};

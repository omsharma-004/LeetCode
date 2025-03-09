class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int left = 0;
        int right = 1;
        int count = 0;
        while (right < 2 * n && left < n) {
            if (colors[(right - 1) % n] == colors[right % n])
                left = right;
            if (right - left + 1 == k) {
                count++;
                left++;
            }
            right++;
        }
        return count;
    }
};
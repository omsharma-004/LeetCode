class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        
        // Flatten the grid
        for (auto &row : grid) {
            for (int val : row) {
                nums.push_back(val);
            }
        }

        // Sort the elements
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int median = nums[n / 2]; // Optimal target value
        int cnt = 0;

        // Calculate the number of operations
        for (int num : nums) {
            int diff = abs(num - median);
            if (diff % x != 0) return -1; // Impossible case
            cnt += diff / x;
        }

        return cnt;
    }
};
class Solution {
public:
    bool check(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > nums[(i + 1) % nums.size()])
                ans++;
            if (ans > 1)
                return false;
        }
        return true;
    }
};
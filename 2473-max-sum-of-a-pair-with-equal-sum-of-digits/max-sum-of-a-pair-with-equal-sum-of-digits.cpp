class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, priority_queue<int>> mp;
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            int n = nums[i];
            while (n > 0) {
                int last = n % 10;
                sum += last;
                n = n / 10;
            }
            mp[sum].push(nums[i]);
        }
        int maxi = -1;
        for (auto it : mp) {
            if (it.second.size() >= 2) {
                int last = it.second.top();
                it.second.pop();
                int secondLast = it.second.top();
                maxi = max(maxi, last + secondLast);
            }
        }
        return maxi;
    }
};
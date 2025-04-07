class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2 != 0)
            return false;

        int x = total / 2;
        unordered_set<int> sums;
        sums.insert(0);

        for (int num : nums) {
            unordered_set<int> newsum = sums;
            for (int s : sums)
                newsum.insert(s + num);
            sums = newsum;
        }

        return sums.find(x) != sums.end();
    }
};
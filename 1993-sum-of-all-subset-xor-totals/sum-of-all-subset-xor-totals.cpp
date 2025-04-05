class Solution
{
public:
    int subsetXORSum(vector<int> &nums)
    {
        int n = nums.size();
        int total = 1 << n; // total subsets = 2^n
        int xorTotal = 0;

        for (int mask = 0; mask < total; mask++)
        {
            int xorSum = 0;
            for (int i = 0; i < n; i++)
            {
                // if the i-th bit is set in mask, include nums[i] in subset
                if (mask & (1 << i))
                    xorSum ^= nums[i];
            }
            xorTotal += xorSum; // add this subset's XOR to the total
        }

        return xorTotal;
    }
};
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) 
    {
        int possum = INT_MIN, negsum = INT_MAX;
        int curpos = 0, curneg = 0;
        
        for(int n : nums)
        {
            curpos += n;
            curneg += n;
            
            possum = max(possum, curpos);
            negsum = min(negsum, curneg);
            
            if (curpos < 0)
                curpos = 0;
            if (curneg > 0)
                curneg = 0;
        }
        
        return max(possum, -negsum);
    }
};
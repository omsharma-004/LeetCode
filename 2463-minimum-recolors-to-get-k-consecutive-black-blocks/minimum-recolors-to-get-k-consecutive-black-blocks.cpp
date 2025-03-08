class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        
        int countB = 0;
        int ans = numeric_limits<int>::max();
        for(int i = 0; i < blocks.length(); i++)
        {
            if(i - k >= 0 && blocks[i-k] == 'B') countB--;
            if(blocks[i] == 'B') countB++;
            ans = min(ans, k - countB);
        }
        return ans;
    }
};
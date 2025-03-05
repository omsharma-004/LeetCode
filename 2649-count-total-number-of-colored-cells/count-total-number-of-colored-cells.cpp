class Solution {
public:
    long long coloredCells(int n) { 
        return 4 * (long long)(n - 1) * n / 2 + 1; 
    }
};
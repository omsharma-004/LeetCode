class Solution {
public:
    string convert(const string &s, int numRows) {
        if(numRows <= 1 || (int)s.size() <= numRows) return s;
        int n = (int)s.size();
        int cycle = (numRows - 1) << 1;
        string ans(n, '\0');
        int idx = 0;
        for(int r = 0; r < numRows; r++) {
            for(int i = r; i < n; i += cycle) {
                ans[idx++] = s[i];
                if(r > 0 && r < numRows - 1) {
                    int j = i + cycle - (r << 1);
                    if(j < n) ans[idx++] = s[j];
                }
            }
        }
        return ans;
    }
};
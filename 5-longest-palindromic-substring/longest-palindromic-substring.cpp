class Solution {
public:
    string longestPalindrome(string s) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n = s.size();
        int start = 0, maxLen = 0;
        for (int i = 0; i < n; i++) {
            for (int l : {i, i + 1}) {
                int j = i;
                while (j >= 0 && l < n && s[j] == s[l]) {
                    j--;
                    l++;
                }
                if (l - j - 1 > maxLen) {
                    start = j + 1;
                    maxLen = l - j - 1;
                }
            }
        }
        return s.substr(start, maxLen);
    }
};

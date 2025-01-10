class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        unordered_set<char> set;
        int start = 0;
        int maxLength = 0;
        for (int i = 0; i < s.length(); i++) {
            while (set.find(s[i]) != set.end()) {
                set.erase(s[start]);
                start++;
            }
            set.insert(s[i]);
            maxLength = max(maxLength, i - start + 1);
        }
        return maxLength;
    }
};

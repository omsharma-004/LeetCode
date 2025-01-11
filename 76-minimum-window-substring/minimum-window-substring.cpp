class Solution {
public:
    string minWindow(string s, string t) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        if (s.empty() || t.empty())
            return "";
        unordered_map<char, int> tmap;
        for (char ch : t) {
            tmap[ch]++;
        }
        int i = 0, j = 0, count = t.length();
        int n = s.length();
        int minLen = INT_MAX;
        int start = 0;
        while (j < n) {
            if (tmap.find(s[j]) != tmap.end()) {
                tmap[s[j]]--;
                if (tmap[s[j]] >= 0) {
                    count--;
                }
            }
            j++;
            while (count == 0) {
                if (j - i < minLen) {
                    minLen = j - i;
                    start = i;
                }
                if (tmap.find(s[i]) != tmap.end()) {
                    tmap[s[i]]++;
                    if (tmap[s[i]] > 0) {
                        count++;
                    }
                }
                i++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
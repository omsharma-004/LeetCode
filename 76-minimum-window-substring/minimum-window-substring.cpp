class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";

        unordered_map<char, int> tmap;
        for (char ch : t) {
            tmap[ch]++;
        }

        int i = 0, j = 0, count = t.length();
        int n = s.length();
        int minLen = INT_MAX;
        int start = 0;  // To store the start index of the minimum window

        while (j < n) {
            // Move right pointer (expand the window)
            if (tmap.find(s[j]) != tmap.end()) {
                tmap[s[j]]--;
                if (tmap[s[j]] >= 0) {
                    count--;
                }
            }
            j++;

            // Shrink the window when all characters are found
            while (count == 0) {
                if (j - i < minLen) {
                    minLen = j - i;
                    start = i;  // Update the starting index of the minimum window
                }

                // Move left pointer (shrink the window)
                if (tmap.find(s[i]) != tmap.end()) {
                    tmap[s[i]]++;
                    if (tmap[s[i]] > 0) {
                        count++;
                    }
                }
                i++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);  // Return the minimum window substring
    }
};
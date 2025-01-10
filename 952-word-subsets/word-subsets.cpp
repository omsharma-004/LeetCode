class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        unordered_map<char, int> mp1;
        for (const string& word : words2) {
            unordered_map<char, int> mp2;
            for (char c : word) {
                mp2[c]++;
            }
            for (const auto& entry : mp2) {
                mp1[entry.first] =
                    max(mp1[entry.first], entry.second);
            }
        }
        vector<string> result;
        for (const string& word : words1) {
            unordered_map<char, int> mp3;
            for (char c : word) {
                mp3[c]++;
            }
            bool isSubset = true;
            for (const auto& entry : mp1) {
                if (mp3[entry.first] < entry.second) {
                    isSubset = false;
                    break;
                }
            }
            if (isSubset) {
                result.push_back(word);
            }
        }
        return result;
    }
};

class Solution {
public:
    string reverseWords(string s) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        stringstream ss(s);
        vector<string> words;
        string word;
        while (ss >> word) {
            words.push_back(word);
        }
        string result;
        for (int i = words.size() - 1; i >= 0; i--) {
            result += words[i];
            if (i != 0) {
                result += ' ';
            }
        }
        return result;
    }
};

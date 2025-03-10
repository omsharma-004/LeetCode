class Solution {
public:
    long long helper(string word, int k) {
        int n = word.size();
        int l = 0;
        int cons = 0;
        long long count = 0;
        map<char, int> mp;
        set<char> st = {'a', 'e', 'i', 'o', 'u'};
        for (int r = 0; r < n; r++) {
            if (st.find(word[r]) != st.end())
                mp[word[r]]++;
            else
                cons++;
            while (mp.size() == 5 && cons > k) {
                if (st.find(word[l]) != st.end()) {
                    mp[word[l]]--;
                    if (mp[word[l]] == 0)
                        mp.erase(word[l]);
                } else
                    cons--;
                l++;
            }
            count += (r - l + 1);
        }
        return count;
    }
    long long countOfSubstrings(string word, int k) {
        return helper(word, k) - helper(word, k - 1);
    }
};
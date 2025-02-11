class Solution {
public:
    string removeOccurrences(string s, string part) {
        string st;
        for (int i = 0; i < s.length(); i++) {
            st.push_back(s[i]);
            if (st.size() >= part.length() &&
                st.substr(st.size() - part.length()) == part) {
                st.erase(st.size() - part.length());
            }
        }
        return st;
    }
};
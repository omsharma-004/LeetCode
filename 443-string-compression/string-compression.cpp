class Solution {
public:
    int compress(std::vector<char>& s) {
        vector<char> ans;
        int n = s.size();
        int i = 0;
        while (i < n) {
            char currentChar = s[i];
            int count = 0;
            while (i < n && s[i] == currentChar) {
                count++;
                i++;
            }
            ans.push_back(currentChar);
            if (count > 1) {
                string countStr = to_string(count);
                for (char ch : countStr) {
                    ans.push_back(ch);
                }
            }
        }
        s = ans;
        return ans.size();
    }
};

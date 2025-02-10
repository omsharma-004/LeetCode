class Solution {
public:
    string clearDigits(string s) {
        int count = 0;
        string result = "";
        int n = s.size();
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] >= '0' && s[i] <= '9') {
                count++;
            } else {
                if (count != 0) count--;
                else    result += s[i];
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
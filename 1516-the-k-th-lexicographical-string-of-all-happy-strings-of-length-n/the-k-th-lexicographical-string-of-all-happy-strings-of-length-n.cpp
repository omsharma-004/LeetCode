class Solution {
public:
    void backtrack(string& temp, int &k, int n, string &ans) {
        if (temp.size() == n) {
            k--;
            if (k == 0) {
                ans = temp;
            }
            return;
        }
        if (!ans.empty()) return;

        for (char i = 'a'; i <= 'c'; i++) {
            if (temp.empty() || temp.back() != i) {
                temp.push_back(i);
                backtrack(temp, k, n, ans);
                temp.pop_back();
                if (!ans.empty()) return;
            }
        }
    }

    string getHappyString(int n, int k) {
        if (n == 0) return "";
        string ans = "";
        string temp = "";
        backtrack(temp, k, n, ans);
        return ans;
    }
};
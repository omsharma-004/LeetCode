class Solution {
public:
    int numberOfSubstrings(string s) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int i = 0;
        int j = 0;
        int a = 0;
        int b = 0;
        int c = 0;
        int n = s.size();
        int ans = 0;
        while (j < s.size()) {
            if (s[j] == 'a')
                a++;
            if (s[j] == 'b')
                b++;
            if (s[j] == 'c')
                c++;
            while (a && b && c && i < j) {
                ans += n - j;
                if (s[i] == 'a')
                    a--;
                if (s[i] == 'b')
                    b--;
                if (s[i] == 'c')
                    c--;
                i++;
            }
            j++;
        }
        return ans;
    }
};
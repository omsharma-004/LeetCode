class Solution {
public:
    int minimumRecolors(string str, int length) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        const int n = str.size();
        int count = 0;
        for (int i = 0; i < length; ++i)
            count += str[i] == 'W';
        int mincount = count;
        for (int i = length; i < n; ++i) {
            count += str[i] == 'W';
            count -= str[i - length] == 'W';
            mincount = min(mincount, count);
        }
        return mincount;
    }
};

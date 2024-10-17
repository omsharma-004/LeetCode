class Solution {
public:
    int maximumSwap(int num) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        string str = to_string(num);
        vector<int> ans(10, -1);
        for (int i=0;i<str.size();i++) {
            ans[str[i]-'0'] = i;
        }
        for (int i=0;i<str.size();i++) {
            for (int d=9;d>str[i]-'0';d--) {
                if (ans[d]>i) {
                    swap(str[i],str[ans[d]]);
                    return stoi(str);
                }
            }
        }
        return num;
    }
};

class Solution {
public:
    int minimumLength(string s) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n = s.length(), del = 0;
        unordered_map<char, int> mp;
        for(int i = 0; i < n; i++){
            mp[s[i]]++;
        }
        for(auto ele : mp){
            int freq = ele.second;
            del += (freq%2) ? freq - 1 : freq - 2;
        }
        return n - del;
    }
};
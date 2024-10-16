class Solution {
public:
    int maxVowels(string s, int k) {
        int ans = 0;
        int mx = 0;
        unordered_set<char> s1={'a', 'e', 'i', 'o', 'u'};
        for(int i=0;i< s.size();i++) {
            if(s1.count(s[i])) mx++;
            if (i>=k) {
                if(s1.count(s[i-k])) mx--;
            }
            ans=max(ans, mx);
        }
        return ans;
    }
};
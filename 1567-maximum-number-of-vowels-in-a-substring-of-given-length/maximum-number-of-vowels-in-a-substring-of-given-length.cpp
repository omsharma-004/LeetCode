class Solution {
public:
    int maxVowels(string s, int k) {
        int ans = 0;
        int mx = 0;
        string v = "aeiou";
        for(int i=0;i<s.size();i++){
            if(v.find(s[i]) != string::npos) mx++;
            if(i>=k){
                if(v.find(s[i-k]) != string::npos) mx--;
            }
            ans=max(ans,mx);
        }
        return ans;
    }
};

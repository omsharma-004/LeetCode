class Solution {
public:
    string removeStars(string s) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int i=0,j=0;
        for(i=0;i<s.size();i++){
            if(s[i]=='*'){
                j--;
            }else{
                s[j++] = s[i];
            }
        }
        return s.substr(0,j);
    }
};
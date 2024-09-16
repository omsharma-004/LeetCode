// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         sort(s.begin(),s.end());
//         sort(t.begin(),t.end());
//         if(s==t) return true;
//         else return false;
//     }
// };

//USING MAPS
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(t.length()!=s.length()) return false;
        unordered_map<char, int> mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        for(int i=0;i<s.length();i++){
            char ch=t[i];
            if(mp.find(ch)!=mp.end()){
                mp[ch]--;
                if(mp[ch]==0) mp.erase(ch);
            }
            else return false;
        }
        if(mp.size()>0) return false;
        return true;
    }
};
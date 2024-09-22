class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length()!=word2.length()) return false;
        unordered_map<char, int> mp1, mp2;
        for(auto i : word1){
            mp1[i]++;
        }
        for(auto i : word2){
            mp2[i]++;
        }
        for(auto i:mp2){
            char ch=i.first;
            if(mp1.find(ch)==mp1.end()) return false;
        }
        unordered_map<int, int> m1, m2;
        for(auto i:mp1){
            int x=i.second;
            m1[x]++;
        }
        for(auto i:mp2){
            int x=i.second;
            m2[x]++;
        }
        for(auto i:m2){
            int x=i.first;
            if(m1.find(x)==m1.end()) return false;
            if(m1[x]!=m2[x]) return false;
        }
        return true;
    }
};
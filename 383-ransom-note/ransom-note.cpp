class Solution {
public:
    bool canConstruct(string a, string b) {
        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;
        for(auto i:a){
            mp1[i]++;
        }
        for(auto i:b){
            mp2[i]++;
        }
        for (auto& entry : mp1) {
            char ch = entry.first;
            int count = entry.second;
            if (mp2[ch] < count) return false;
        }
        return true;
    }
};
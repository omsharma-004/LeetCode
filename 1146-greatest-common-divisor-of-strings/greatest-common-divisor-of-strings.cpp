class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        if(str1 + str2 != str2 + str1) return "";
        return str1.substr(0, gcd(str1.size(), str2.size()));
    }
};
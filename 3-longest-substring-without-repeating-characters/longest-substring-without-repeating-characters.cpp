// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int st=0;
//         int count=0;
//         int fast=0;
//         for(int i=1;i<s.length();i++){
//             if(s[st]!=s[i] && s[fast]!=s[i]){
//                 count++;
//                 i++;
//                 st++;
//             }
//             else{
//                 st++;
//                 fast++;
//             }
//         }
//         return count+1;
//     }
// };
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen; // To store characters in the current window
        int start = 0; // Start of the window
        int maxLength = 0; // To store the maximum length
        
        for (int end = 0; end < s.length(); end++) {
            // If the character at 'end' is in the window, move 'start' forward
            while (seen.find(s[end]) != seen.end()) {
                seen.erase(s[start]);
                start++;
            }
            // Add the current character to the window
            seen.insert(s[end]);
            
            // Update the maximum length
            maxLength = max(maxLength, end - start + 1);
        }
        
        return maxLength;
    }
};

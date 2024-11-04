class Solution {
public:
    string compressedString(string word) {
        string s="";
        int n=word.length();
        int i=0;
        int j=0;
        int count=0;
        while(j<n){
            count=0;
            while(j<n && word[i]==word[j] && count<9){
                j++;
                count++;
            }
            s+=to_string(count)+word[i];
            i=j;
        }
        return s;
    }
};
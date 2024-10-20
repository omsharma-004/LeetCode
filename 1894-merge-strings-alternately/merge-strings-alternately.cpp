class Solution {
public:
    string mergeAlternately(string words1, string words2) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        string a="";
        int i=0;
        int j=0;
        while(i<words1.size() && j<words2.size()){
            a+=words1[i];
            a+=words2[j];
            i++;
            j++;
        }
        while(j<words2.size()){
            a+=words2[j];
            j++;
        }
        while(i<words1.size()){
            a+=words1[i];
            i++;
        }
        return a;
    }
};
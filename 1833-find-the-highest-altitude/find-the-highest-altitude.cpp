class Solution {
public:
    int largestAltitude(vector<int>& gains) {
        for(int i=1;i<gains.size();i++){
            gains[i]+=gains[i-1];
        }
        int maxval=INT_MIN;
        for(int i=0;i<gains.size();i++){
            maxval=max(maxval,gains[i]);
        }
        if(maxval<0) return 0;
        else return maxval;
    }
};
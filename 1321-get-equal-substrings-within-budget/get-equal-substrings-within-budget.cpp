class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n=s.length();
        vector<int> v(n);
        for (int i=0;i<n;i++){
            v[i]=abs(s[i]-t[i]);
        }
        int lo=0;
        int res=INT_MIN;
        int curr=0;
        for (int hi=0;hi<n;hi++){
            curr+=v[hi];
            while(curr>maxCost){
                curr-=v[lo++];
            }
            res=max(res, hi-lo+1);
        }
        return res;
    }
};
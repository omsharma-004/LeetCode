class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        vector<int>& v= satisfaction;
        sort(v.begin(), v.end());
        int n=v.size();
        int suf[n];
        suf[n-1]=v[n-1];
        for(int i=n-2;i>=0;i--){
            suf[i] = suf[i+1] + v[i];
        }
        int idx=-1;
        for(int i=0;i<n;i++){
            if(suf[i]>=0){
                idx=i;
                break;
            }
        }
        if(idx==-1) return 0;
        int x=1;
        int maxsum=0;
        for(int i=idx;i<n;i++){
            maxsum += v[i]*x;
            x++;
        }
        return maxsum;
    }
};
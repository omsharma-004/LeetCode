class Solution {
public:
    int numRescueBoats(vector<int>& v, int k) {
        sort(v.begin(), v.end());
        int ans = 0;
        int j = v.size()-1;
        int i=0;
        while(i<=j){
            if(v[i]+v[j]<=k){
                ans++;
                i++;
                j--;
            }
            else{
                ans++;
                j--;
            }
        }
        return ans;
    }
};
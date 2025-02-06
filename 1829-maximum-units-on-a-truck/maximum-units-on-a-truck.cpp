bool cmp(vector<int>& a, vector<int>& b){
    return a[1]>b[1];
}
class Solution {
public:
    int maximumUnits(vector<vector<int>>& v, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int res=0;
        sort(v.begin(), v.end(), cmp);
        for(int i=0;i<v.size();i++){
            if(v[i][0]<=k){
                res+=v[i][0]*v[i][1];
                k-=v[i][0];
            }
            else{
                res+=k*v[i][1];
                k=0;
            }
            if(k==0) break;
        }
        return res;
    }
};
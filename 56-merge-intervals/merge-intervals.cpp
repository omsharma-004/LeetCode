bool cmp(vector<int>& a, vector<int>& b){
    return a[1]<b[1];
}
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end(), cmp);
        int n=arr.size();
        ans.push_back(arr[n-1]);
        for(int i=n-2;i>=0;i--){
            vector<int> curr=arr[i];
            if(curr[1]>=ans[ans.size()-1][0]){
                ans[ans.size()-1][0]=min(curr[0],ans[ans.size()-1][0]);
                ans[ans.size()-1][1]=max(curr[1],ans[ans.size()-1][1]);
            }
            else{
                ans.push_back(arr[i]);
            }
        }
        return ans;
    }
};
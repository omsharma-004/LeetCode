bool cmp(vector<int>& a, vector<int>& b){
    return a[0]<b[0];
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
        ans.push_back(arr[0]);
        for(int i=1;i<n;i++){
            vector<int> curr=arr[i];
            if(curr[0]<=ans[ans.size()-1][1]){
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
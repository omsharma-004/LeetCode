class Solution {
public:
    int equalPairs(vector<vector<int>>& arr) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n=arr.size();
        int count=0;
        map<vector<int>, int> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        for(int j=0;j<n;j++){
            vector<int> temp;
            for(int i=0;i<n;i++){
                temp.push_back(arr[i][j]);
            }
            if(mp.find(temp)!=mp.end()){
                count+=mp[temp];
            }
        }
        return count;
    }
};
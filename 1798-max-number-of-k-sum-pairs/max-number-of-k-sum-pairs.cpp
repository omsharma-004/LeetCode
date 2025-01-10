class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        unordered_map<int, int> mp;
        int count=0;
        for(auto i:nums){
            if(mp[k-i]>0){
                count++;
                mp[k-i]--;
            }
            else{
                mp[i]++;
            }
        }
        return count;
    }
};
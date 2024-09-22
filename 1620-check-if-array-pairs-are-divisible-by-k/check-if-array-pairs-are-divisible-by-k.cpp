class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for(auto x:arr){
            int i=((x%k)+k)%k;
            mp[i]++;
        }
        if(mp.find(0)!=mp.end()){
            if(mp[0]%2!=0) return false;
            mp.erase(0);
        }
        for(auto x:mp){
            int i=x.first;
            int rem=k-i;
            if(mp.find(rem)==mp.end()) return false;
            if(mp[rem]!=mp[i]) return false;
        }
        return true;
    }
};
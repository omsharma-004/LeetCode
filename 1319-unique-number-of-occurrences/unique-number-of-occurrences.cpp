class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mp;
        unordered_set<int> st;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        for(auto i:mp){
            int freq=i.second;
            if(st.find(freq)!=st.end()) return false;
            else st.insert(freq);
        }
        return true;
    }
};
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp1;
        unordered_map<int, int> mp2;
        vector<int> v;
        for(auto i:nums1){
            mp1[i]++;
        }
        for(auto i:nums2){
            mp2[i]++;
        }
        for(auto i:mp1){
            if(mp2.find(i.first)!=mp2.end()){
                v.push_back(i.first);
            }
        }
        return v;
    }
};
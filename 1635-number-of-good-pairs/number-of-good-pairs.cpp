class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int count = 0;
        unordered_map<int, int> mymap;
        for (int num : nums) {
            mymap[num]++;
        }
        for (auto i = mymap.begin(); i != mymap.end(); i++) {
            int pairs = i->second * (i->second - 1) / 2;
            count += pairs;
        }
        return count;
    }
};
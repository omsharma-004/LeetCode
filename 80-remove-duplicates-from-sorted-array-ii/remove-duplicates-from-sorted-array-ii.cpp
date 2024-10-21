class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        unordered_map<int, int> mp;
        for (auto i : nums) {
            mp[i]++;
        }
        vector<int> uniqueElements;
        for (const auto& entry : mp) {
            uniqueElements.push_back(entry.first);
        }
        int c=0;
        sort(uniqueElements.begin(), uniqueElements.end());
        for (const auto& num : uniqueElements) {
            int occurrences = std::min(mp[num], 2);
            for (int j = 0; j < occurrences; j++) {
                nums[c++] = num;
            }
        }
        return c;
    }
};

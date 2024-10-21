// class Solution {
// public:
//     int removeDuplicates(std::vector<int>& nums) {
//         ios_base::sync_with_stdio(0);
//         cin.tie(0);
//         cout.tie(0);
//         unordered_map<int, int> mp;
//         for (auto i : nums) {
//             mp[i]++;
//         }
//         vector<int> uniqueElements;
//         for (const auto& entry : mp) {
//             uniqueElements.push_back(entry.first);
//         }
//         int c=0;
//         sort(uniqueElements.begin(), uniqueElements.end());
//         for (const auto& num : uniqueElements) {
//             int occurrences = std::min(mp[num], 2);
//             for (int j = 0; j < occurrences; j++) {
//                 nums[c++] = num;
//             }
//         }
//         return c;
//     }
// };

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) return nums.size();
        int index = 2;
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] != nums[index - 2]) {
                nums[index] = nums[i];
                index++;
            }
        }
        return index;
    }
};

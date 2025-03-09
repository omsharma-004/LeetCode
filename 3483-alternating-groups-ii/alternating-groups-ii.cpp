class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& arr, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int ans = 0;
        vector<int> v(arr.begin(), arr.end());
        for (auto i : arr) {
            v.push_back(i);
            if (arr.size() + k - 1 == v.size())
                break;
        }
        for (int i = 0; i < arr.size();) {
            int j = i + 1;
            while (j < v.size() && v[j - 1] != v[j])
                j++;
            if (j - i >= k)
                ans += (j - i + 1 - k);
            i = j;
        }
        return ans;
    }
};
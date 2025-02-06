class Solution {
public:
    int numRescueBoats(vector<int>& v, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int ans = 0;
        sort(v.begin(), v.end());
        int left = 0;
        int right = v.size() - 1;
        while (left <= right) {
            if (v[left] + v[right] <= k) {
                left++;
                right--;
            } else
                right--;
            ans++;
        }
        return ans;
    }
};
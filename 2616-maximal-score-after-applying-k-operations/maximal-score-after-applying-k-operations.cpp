class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        priority_queue<int> pq(nums.begin(), nums.end());
        long long ans = 0;
        while (k--) {
            int v = pq.top();
            pq.pop();
            ans += v;
            pq.push((v + 2) / 3);
        }
        return ans;
    }
};

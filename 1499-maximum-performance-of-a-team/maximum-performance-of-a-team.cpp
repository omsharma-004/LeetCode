#define pp pair<long long int, long long int>

class Solution {
public:
    int maxPerformance(int n, vector<int>& sp, vector<int>& eff, int k) {
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++) {
            v.push_back({eff[i], sp[i]});
        }
        sort(v.rbegin(), v.rend());
        priority_queue<int, vector<int>, greater<int>> pq;
        long long int sum = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            sum += v[i].second;
            pq.push(v[i].second);
            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            ans = max(ans, sum * v[i].first);
        }
        return ans % 1000000007;
    }
};
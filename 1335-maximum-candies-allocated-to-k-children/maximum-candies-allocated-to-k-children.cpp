class Solution {
public:
    bool helper(vector<int>& v, int n, long long k, long long val) {
        long long p = 0;
        for (int i = 0; i < n; i++) {
            p = p + ((long long)v[i] / val);
        }
        return (p >= k);
    }

    int maximumCandies(vector<int>& can, long long k) {
        long long total = 0;
        int n = can.size();
        for (auto c : can) {
            total = total + (long long)c;
        }
        long long lo = 1;
        long long hi = total / k;
        long long ans = 0;
        while (lo <= hi) {
            long long mid = lo + (hi - lo) / 2;
            if (helper(can, n, k, mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};
class Solution {
public:
    bool helper(vector<int>& ranks, long long& limit, int& cars) {
        long long count = 0;
        for (int& i : ranks) {
            count += sqrt(limit / i);
        }
        return count >= cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        int minr = *min_element(ranks.begin(), ranks.end());
        long long lo = 1;
        long long hi = 1LL * minr * cars * cars;
        long long ans = hi, mid;
        while (lo <= hi) {
            mid = (lo + hi) / 2;
            if (helper(ranks, mid, cars)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};
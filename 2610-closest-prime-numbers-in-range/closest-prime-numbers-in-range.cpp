class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> v;
        if (left == 1)
            left++;
        for (int i = left; i <= right; i++) {
            bool ok = true;
            for (int j = 2; 1LL * j * j <= i; j++) {
                if (i % j == 0) {
                    ok = false;
                    break;
                }
            }
            if (ok == true) {
                v.push_back(i);
            }
        }
        if (v.size() < 2) {
            v.clear();
            v.push_back(-1);
            v.push_back(-1);
            return v;
        }
        sort(v.begin(), v.end());
        int dif = INT_MAX;
        int fast, last;
        for (int i = 1; i < v.size(); i++) {
            if (v[i] - v[i - 1] < dif) {
                fast = v[i - 1];
                last = v[i];
                dif = v[i] - v[i - 1];
            }
        }
        return {fast, last};
    }
};
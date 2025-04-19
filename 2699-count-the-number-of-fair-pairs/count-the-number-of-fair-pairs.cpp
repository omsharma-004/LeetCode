class Solution {
public:
    long long countFairPairs(vector<int>& n, int lower, int upper) {
            long long answer = 0;
            sort(n.begin(), n.end());
            for (int i = 0; i + 1 < n.size(); i++) {
                int min = lower - n[i], max = upper - n[i];
                auto high = upper_bound(n.begin() + i + 1, n.end(), max);
                auto low = lower_bound(n.begin() + i + 1, n.end(), min);
                answer += (high - low);
            }
            return answer;
    }
};
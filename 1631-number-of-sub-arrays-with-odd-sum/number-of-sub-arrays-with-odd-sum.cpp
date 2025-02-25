class Solution {
public:
    int M = 1e9 + 7;
    int numOfSubarrays(vector<int>& arr) {
        int odd = 0;
        int even = 1;
        int ret = 0;
        int sum = 0;
        for (int i : arr) {
            sum += i;
            if (sum % 2) {
                odd++;
                ret += even;
            } else {
                even++;
                ret += odd;
            }
            ret = ret % M;
        }
        return ret % M;
    }
};
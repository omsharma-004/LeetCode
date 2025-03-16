class Solution {
public:
    bool isPossibleToDoAllCars(vector<int>& ranks, int cars, long long maxTime) {
        for(int rank : ranks) {
            int carAllotment = floor(sqrt(maxTime / rank));
            cars -= carAllotment;
            if(cars <= 0) return true;
        }
        return false;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        int maxElem = *max_element(ranks.begin(), ranks.end());
        long long start = 1, end = (long long)maxElem * cars * cars;
        while(start <= end) {
            long long mid = (start + end) / 2;
            if(isPossibleToDoAllCars(ranks, cars, mid)) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return start;
    }
};
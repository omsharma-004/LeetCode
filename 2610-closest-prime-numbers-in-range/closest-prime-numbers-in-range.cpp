class Solution {
public:
vector<bool> helper(int right){
        vector<bool> isPrime(right + 1, true);
        isPrime[0] = isPrime[1] = false;

        for(int i = 2; i * i <= right; i++){
            if(isPrime[i]){
                for(int j = 2; i * j <= right; j++){
                    isPrime[i * j] = false;
                }
            }
        }
        return isPrime;
    }
    vector<int> closestPrimes(int left, int right) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<bool> isPrime = helper(right);
        vector<int> prime;

        for(int num = left; num <= right; num++){
            if(isPrime[num]){
                prime.push_back(num);
            }
        }

        int minDiff = INT_MAX;
        vector<int> result = {-1, -1};

        for(int i = 1; i < prime.size(); i++){
            int diff = prime[i] - prime[i-1];
            if(diff < minDiff){
                minDiff = diff;
                result = {prime[i-1], prime[i]};
            }
        }
        return result;
    }
};

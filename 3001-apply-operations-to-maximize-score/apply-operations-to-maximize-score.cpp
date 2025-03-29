#include <vector>
#include <stack>
#include <queue>
#include <algorithm> // for std::max

using namespace std;

class Solution {
private:
    int countDistinctPrimeFactors(int n) {
        int count = 0;

        // Check for factor 2
        if (n % 2 == 0) {
            count++;
            while (n % 2 == 0) {
                n /= 2;
            }
        }

        // Check for odd factors
        for (long long i = 3; i * i <= n; i += 2) {
            if (n % i == 0) {
                count++;
                while (n % i == 0) {
                    n /= i;
                }
            }
        }

        // If remaining n is a prime
        if (n > 1) count++;
        return count;
    }

    int modPow(int base, int exp, int mod) {
        long long result = 1;
        long long b = base % mod;
        while (exp > 0) {
            if (exp & 1) {
                result = (result * b) % mod;
            }
            b = (b * b) % mod;
            exp >>= 1;
        }
        return (int)result;
    }

public:
    int maximumScore(vector<int>& nums, int k) {
        int n = (int)nums.size();
        if (n == 0) return 1;

        // Priority queue to store (value, index) of nums
        priority_queue<pair<int,int>> maxValues;
        // 'rightLarge' tracks for each index i, where the "next larger element" is
        vector<int> rightLarge(n, n);
        // 'LeftLarge' will track for each index i, where the "previous larger element" is
        vector<int> LeftLarge(n, -1);

        // We'll use two stacks of indices
        stack<int> st;
        stack<int> reverse;

        // Also store primeScores for each element
        vector<int> primeScores(n, 0);

        for (int i = 0; i < n; i++) {
            primeScores[i] = countDistinctPrimeFactors(nums[i]);
            maxValues.emplace(nums[i], i);

        }

        for (int i = 0; i < n; i++) {
            while (!st.empty() && primeScores[i] > primeScores[st.top()]) {   
                rightLarge[st.top()] = i;
                st.pop();
            }
            st.push(i); 
        }

        for (int i = n - 1; i >= 0; i--) {
            while (!reverse.empty() && primeScores[i] >= primeScores[reverse.top()]) { 
                LeftLarge[reverse.top()] = i;
                reverse.pop();
            }
            reverse.push(i);                                   
        }

        int score = 1;
        const int MODULE = 1000000007;

        // Pop the (value, index) pairs in descending order
        while (!maxValues.empty() && k > 0) {
            auto [val, idx] = maxValues.top();
            maxValues.pop();

            // 't' is how many positions we can "use" from idx's span
            long long t = 1LL * (rightLarge[idx] - idx) * (idx - LeftLarge[idx]);
            long long steps = min(t, (long long)k);

            int multiply = modPow(val, (int)steps, MODULE);
            score = (int)((1LL * score * multiply) % MODULE);

            k -= steps;
        }
        return score % MODULE;
    }
};
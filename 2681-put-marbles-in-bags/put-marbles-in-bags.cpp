class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n=weights.size()-1;
        std::vector<int> pairs;
        pairs.reserve(n);
        for (int i=0;i<n+1;i++){
            // pairs.push_back(weights[i]*2);
            if(i!=n)pairs.push_back(weights[i]+weights[i+1]);
        }
        std::sort(pairs.begin(),pairs.end());
        long long ma{},mi{};
        for (int i=0;i<k-1;i++){
            ma+=pairs[n-1-i];
            mi+=pairs[i];
        }
        return ma-mi;
    }
};
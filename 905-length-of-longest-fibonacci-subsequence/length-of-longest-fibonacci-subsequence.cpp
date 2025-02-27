class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_set<int>s(arr.begin(), arr.end());
        int n = arr.size(), result = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int first = arr[i], second = arr[j], length = 2, aux;
                while (s.count(first + second)) {
                    aux = second;
                    second = first + second;
                    first = aux;
                    length++;
                }
                result = max(result, length);
            }         
        }
        return result < 3 ? 0 : result;
    }
};
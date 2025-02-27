class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int curLen = 0,ind = j;
                int first = arr[i], second = arr[j];
                while (ind != n) {
                    ind = lower_bound(arr.begin() + ind + 1, arr.end(),first + second) - arr.begin();
                    if(ind < n && arr[ind] == first + second){
                        first = second;
                        second = arr[ind];
                        curLen++;
                    }else
                    {
                        break;
                    }
                }
                maxLen = max(maxLen, curLen);
            }
        }
        return (maxLen == 0 ? 0 : maxLen + 2);
    }
};
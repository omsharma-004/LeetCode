class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; i++) {
            pq.push(binaryToNum(nums[i]));
        }
        int num = 0;
        while (!pq.empty()) {
            if (pq.top() != num)
                break;
            num++;
            pq.pop();
        }
        if (pq.empty())
            num = pow(2, n) - 1;
        string res;
        for (int i = 0; i < n; i++) {
            res = to_string(num % 2) + res;
            if (num % 2)
                num--;
            num /= 2;
        }
        return res;
    }
    int binaryToNum(string s) {
        int num = 0;
        for (auto c : s) {
            num = num * 2 + c - '0';
        }
        return num;
    }
};
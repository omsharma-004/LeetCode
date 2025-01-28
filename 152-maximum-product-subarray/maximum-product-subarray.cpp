class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int front = 1;
        int rear = 1;
        int n = nums.size();
        int ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (front == 0)
                front = 1;
            if (rear == 0)
                rear = 1;
            front = front * nums[i];
            rear = rear * nums[n - i - 1];
            ans = max(ans, max(front, rear));
        }
        return ans;
    }
};
class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> pq;
        double ts = 0.0;
        for (int i = 0; i < nums.size(); i++) {
            ts += nums[i];
            pq.push((nums[i] * 1.0));
        }
        int ans = 0;
        double fs = ts / 2.0;
        while (ts > fs) {
            double a = pq.top();
            pq.pop();
            ts -= ((a) / 2.0);
            pq.push((a) / 2.0);
            ans++;
        }
        return ans;
    }
};
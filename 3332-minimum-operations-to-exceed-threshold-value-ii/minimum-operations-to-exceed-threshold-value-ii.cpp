class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int count=0;
        long long int t1=0,t2=0;
        priority_queue<long long int, vector<long long int>, greater<long long int>>n; 
        for(auto a:nums)
            n.push(a);
        while(n.top()<k)
        {
            t1=n.top();
            n.pop();
            t2=n.top();
            n.pop();
            long long int s=min(t1,t2)*2 + max(t1,t2);
            n.push(s);
            count++;
        }
        return count;
    }
};
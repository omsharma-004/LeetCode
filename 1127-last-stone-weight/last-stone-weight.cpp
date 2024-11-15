class Solution {
public:
    int lastStoneWeight(vector<int>& arr) {
        priority_queue<int> pq(arr.begin(), arr.end());
        while(pq.size()>1){
            int a=pq.top();
            pq.pop();
            int b=pq.top();
            pq.pop();
            int c=abs(a-b);
            if(c>0) pq.push(c);
        }
        if(pq.size()==0) return 0;
        return pq.top();
    }
};
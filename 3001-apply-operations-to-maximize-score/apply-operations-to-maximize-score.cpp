class Solution {
public:
    const int MOD = 1e9 +7;

    long long binaryexp(long long base ,long long exp){
        if(base ==0 || base==1)return base;

        long long ans = 1;

        while(exp>0){
            if(exp%2==0){
                base = (base*base)%MOD;
                exp/=2;
            }else{
                ans = (ans*base)%MOD;
                exp--;
            }
        }
        return ans;
    }

    void calculate_score(vector<long long>&score , vector<int>nums){

        for(long long ele:nums){
            int count =0;
            for(long long i=2;i*i<ele;i++){
                if(ele%i==0){
                    count++;
                }while(ele%i==0)ele/=i;
            }
            if(ele>1)count++;
            score.push_back(count);
        }
    }

    void cal_subcount(vector<long long>& score, vector<long long>& subarray_count) {
    int n = score.size();
    vector<long long> res(n, -1);  // Initialize `res` with -1

    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && score[st.top()] < score[i])
            st.pop();

        if (!st.empty()) res[i] = st.top();

        st.push(i);
    }

    st = stack<int>();  // Clear stack

    long long count;
    for (int i = n - 1; i >= 0; --i) {
        count = 0;
        while (!st.empty() and score[st.top()] <= score[i])
            st.pop();
        if (st.empty())
            count = (n - i) * (i - (res[i] == -1 ? -1 : res[i]));
        else
            count = (st.top() - i) * (i - (res[i] == -1 ? -1 : res[i]));

        st.push(i);
        subarray_count[i] = count;
    }
}


    int maximumScore(vector<int>& nums,long long k) {
        int n = nums.size();
        vector<long long>score;
        calculate_score(score,nums);

        vector<long long>subarray_count(n);
        cal_subcount(score,subarray_count);

        priority_queue<pair<long long ,int>>pq;
        for(int i=0;i<n;i++)
        pq.push({nums[i],i});

        long long ans = 1;
        while(k>0){
            long long curr = pq.top().first;
            int curr_idx = pq.top().second;
            pq.pop();
            ans = (ans*binaryexp(curr,min(k,subarray_count[curr_idx])))%MOD;
            k = k-subarray_count[curr_idx];
        }
        return ans;
    }
};
class Solution {
public:
    long long helper(long long a, long long l, string s){
        string x = to_string(a);
        int pre = x.size() - s.size();
        if(pre < 0) return 0;
        vector<vector<long long>> v(pre+1, vector<long long>(2, 0));
        v[pre][0] = 1;
        v[pre][1] = x.substr(pre) >= s ? 1 : 0;
        for(int i = pre-1; i >= 0; i--){
            int curr = x[i]-'0';
            v[i][0] = (l+1)*v[i+1][0];
            if(curr <= l){
                v[i][1] = (long long)curr*v[i+1][0] + v[i+1][1];
            }else{
                v[i][1] = (long long)(l+1)*v[i+1][0];
            }
        }       
        return v[0][1];
    }
    long long numberOfPowerfulInt(long long st, long long f, int limit, string s) {
        return (helper(f, limit, s) - helper(st-1, limit, s));
    }
};
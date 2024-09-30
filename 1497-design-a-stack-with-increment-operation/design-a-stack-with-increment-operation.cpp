class CustomStack {
private:
    vector<int> s;
    vector<int> ans;
    int i=0;
public:
    CustomStack(int maxSize) {
        s.resize(maxSize);
        ans.resize(maxSize);

    }
    
    void push(int x) {
        if(i<s.size()){
            s[i++]=x;
        }
    }
    
    int pop() {
        if (i <= 0) {
            return -1;
        }
        int result = s[--i] + ans[i];
        if (i > 0) {
            ans[i - 1] += ans[i];
        }
        ans[i] = 0;
        return result;
    }
    
    void increment(int k, int val) {
        if(i>0) ans[min(k,i)-1] +=val;
    }
};
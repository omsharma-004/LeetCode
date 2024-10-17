class Solution {
public:
    vector<int> asteroidCollision(vector<int>& astro) {
        stack<int> st;
        vector<int> ans;
        for(auto i : astro){
            if(st.empty()){
                st.push(i);
            }
            else if(i>0){
                st.push(i);
            }
            else if(i<0){
                while(!st.empty()&&st.top()>0&&st.top()<abs(i)){
                    st.pop();
                }
                if(!st.empty()&&st.top()>0){
                    if(st.top()==abs(i)){
                        st.pop();
                    }
                }
                else{
                    st.push(i);
                }
            }
        }
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
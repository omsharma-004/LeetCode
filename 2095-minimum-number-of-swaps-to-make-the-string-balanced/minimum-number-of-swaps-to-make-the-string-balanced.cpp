class Solution {
public:
    int minSwaps(string s) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        stack<char> st;
        for(char &ch : s) {
            if(ch == '[') st.push(ch);
            else if(!st.empty()) st.pop();
        }       
        return (st.size()+1)/2;
    }
};
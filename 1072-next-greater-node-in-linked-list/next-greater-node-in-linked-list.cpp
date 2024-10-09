class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<int> vals;
        ListNode* slow=head;
        while(slow!=NULL){
            vals.push_back(slow->val);
            slow=slow->next;
        }
        vector<int> ans(vals.size(),0);
        stack<int> st;
        for(int i=0;i<vals.size();i++){
            while(!st.empty() && vals[st.top()]<vals[i]){
                ans[st.top()]=vals[i];
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};
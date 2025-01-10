class Solution {
public:
    int pairSum(ListNode* head) {
        stack<int> st;
        int s=0;
        ListNode* slow=head;
        while(slow!=NULL){
            st.push(slow->val);
            slow=slow->next;
        }
        slow=head;
        int n=st.size();
        int su=0;
        for(int i=0;i<n/2;i++){
            su=st.top()+slow->val;
            st.pop();
            slow=slow->next;
            s=max(su,s);
        }
        return s;
    }
};

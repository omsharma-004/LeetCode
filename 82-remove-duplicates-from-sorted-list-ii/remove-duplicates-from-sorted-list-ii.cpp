class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* slow=dummy;
        ListNode* fast=head;
        while(fast!=NULL){
            if(fast->next!=NULL && fast->val==fast->next->val){
                while(fast->next!=NULL && fast->val==fast->next->val){
                    fast=fast->next;
                }
                slow->next=fast->next;
            }
            else{
                slow=fast;
            }
            fast=fast->next;
        }
        return dummy->next;
    }
};

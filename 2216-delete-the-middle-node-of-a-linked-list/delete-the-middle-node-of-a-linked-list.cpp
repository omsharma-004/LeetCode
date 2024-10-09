class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL || head->next==NULL) return NULL;
        ListNode* slow=head;
        int i=1;
        while(slow->next!=NULL){
            slow=slow->next;
            i++;
        }
        slow=head;
        int a=i/2;
        for(int j=0;j<a-1;j++){
            slow=slow->next;
        }
        slow->next=slow->next->next;
        return head;
    }
};
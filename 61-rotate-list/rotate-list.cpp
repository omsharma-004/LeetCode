class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* tail=head;
        ListNode* slow=head;
        ListNode* fast=head;
        int l=1;
        while(tail->next!=NULL){
            tail=tail->next;
            l++;
        }
        k=k%l;
        int diff=l-k;
        if(k==0){
            return head;
        }
        for(int i=1;i<diff;i++){
            fast=fast->next;
        }
        tail->next=head;
        head=fast->next;
        fast->next=NULL;
            return head;
    }
};
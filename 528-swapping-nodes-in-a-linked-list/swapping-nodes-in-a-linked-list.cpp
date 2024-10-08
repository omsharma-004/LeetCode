class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        if(head==NULL) return NULL;
        ListNode* front=head;
        ListNode* rear=head;
        int i=1;
        while(rear->next!=NULL){
            rear=rear->next;
            i++;
        }
        for(int j=1;j<k;j++){
            front=front->next;
        }
        rear=head;
        for(int j=1;j<i-k+1;j++){
            rear=rear->next;
        }
        int temp=front->val;
        front->val=rear->val;
        rear->val=temp;
        return head;
    }
};
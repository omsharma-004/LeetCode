class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* first=list1;
        ListNode* second=list1;
        for(int i=0;i<a-1;i++){
            first=first->next;
            second=second->next;
        }
        for(int i=0;i<=b-a+1;i++){
            second=second->next;
        }
        ListNode* s2=list2;
        first->next=s2;
        while(s2 && s2->next!=NULL){
            s2=s2->next;
        }
        if (s2) {
            s2->next = second;
        } else {
            first->next = second;
        }
        return list1;
    }
};
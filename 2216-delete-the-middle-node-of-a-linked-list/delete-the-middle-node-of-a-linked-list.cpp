class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        if(!head->next) return NULL;
        fast = fast->next->next;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete(temp);
        return head;
    }
};
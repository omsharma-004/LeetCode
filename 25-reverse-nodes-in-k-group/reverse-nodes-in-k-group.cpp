class Solution {
public:
ListNode* helper(ListNode* head, ListNode* tail) {
    ListNode* prev = NULL;
    ListNode* curr = head;
    while (curr != tail) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    if (head == NULL) return NULL;
    ListNode* tail = head;
    for (int i = 0; i < k; ++i) {
        if (tail == NULL) return head;
        tail = tail->next;
    }
    ListNode* newHead = helper(head, tail);
    head->next = reverseKGroup(tail, k);
    return newHead;
    }
};
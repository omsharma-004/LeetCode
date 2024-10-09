class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        if (!head) return nullptr;
        stack<ListNode*> st;
        ListNode* current = head;
        while (current) {
            while (!st.empty() && st.top()->val < current->val) {
                st.pop();
            }
            st.push(current);
            current = current->next;
        }
        ListNode* newHead = nullptr;
        ListNode* prev = nullptr;
        while (!st.empty()) {
            ListNode* node = st.top();
            st.pop();
            if (!newHead) {
                newHead = node;
                prev = node;
            } else {
                prev->next = node;
                prev = node;
            }
        }
        if (prev) {
            prev->next = nullptr;
        }
        ListNode* finalHead = nullptr;
        current = newHead;
        while (current) {
            ListNode* nextNode = current->next;
            current->next = finalHead;
            finalHead = current;
            current = nextNode;
        }
        return finalHead;
    }
};

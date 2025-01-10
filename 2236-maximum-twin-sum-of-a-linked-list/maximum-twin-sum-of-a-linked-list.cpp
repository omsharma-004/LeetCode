class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> v;
        ListNode* current = head;
        while (current != NULL) {
            v.push_back(current->val);
            current = current->next;
        }
        int a = 0;
        int b = v.size() - 1;
        int maxSum = 0;
        while (a < b) {
            maxSum = max(maxSum, v[a] + v[b]);
            a++;
            b--;
        }
        return maxSum;
    }
};

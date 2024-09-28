class Solution {
public:
    ListNode* helper(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            
        }
        return slow;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return NULL;
        ListNode* mid = helper(head);
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev=NULL;
        while(slow!=mid){
            prev=slow;
            slow=slow->next;
        }
        if(prev!=NULL){
            prev->next=NULL;
        }
        TreeNode* root = new TreeNode(mid->val);
        if (head == mid) return root;
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(mid->next);
        return root;
    }
};


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp1=list1;
        ListNode* temp2=list2;
        ListNode* c=new ListNode(300);
        ListNode* temp3=c;
        while(temp1!=NULL && temp2!=NULL){
            if(temp1->val<=temp2->val){
                temp3->next=temp1;
                temp3=temp3->next;
                temp1=temp1->next;
            }
            else{
                temp3->next=temp2;
                temp3=temp3->next;
                temp2=temp2->next;
            }
        }
        if(temp1==NULL){
            while(temp2!=NULL){
                temp3->next=temp2;
                temp3=temp3->next;
                temp2=temp2->next;
            }
        }
        else if(temp2==NULL){
            while(temp1!=NULL){
                temp3->next=temp1;
                temp3=temp3->next;
                temp1=temp1->next;
            }
        }
        return c->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int a=lists.size();
        if(a==0){
            return NULL;
        }
        while(lists.size()>1){
            ListNode* a=lists[0];
            lists.erase(lists.begin());
            ListNode* b=lists[0];
            lists.erase(lists.begin());
            ListNode* mer=mergeTwoLists(a,b);
            lists.push_back(mer);
        }
        return lists[0];
    }
};
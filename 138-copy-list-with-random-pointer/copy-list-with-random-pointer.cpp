class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* dummy=new Node(0);
        Node* tempd=dummy;
        Node* temp=head;
        while(temp){
            Node* a =new Node(temp->val);
            tempd->next=a;
            tempd=tempd->next;
            temp=temp->next;
        }
        Node* a=head;
        Node* b=dummy->next;
        unordered_map<Node*, Node*> mp;
        Node* tempa=a;
        Node* tempb=b;
        while(tempa){
            mp[tempa]=tempb;
            tempa=tempa->next;
            tempb=tempb->next;
        }
        for(auto i:mp){
            Node* x=i.first;
            Node* y=i.second;
            if(x->random!=NULL){
                Node* oran=x->random;
                Node* dran=mp[x->random];
                y->random=dran;
            }
        }
        return b;
    }
};
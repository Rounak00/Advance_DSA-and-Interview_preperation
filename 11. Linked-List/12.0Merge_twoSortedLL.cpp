Node *sortedMerge(Node *a,Node *b){
    if(a==NULL)return b;
    if(b==NULL)return a;
    Node *head=NULL,*tail=NULL;
    if(a->data<=b->data){
        head=tail=a;a=a->next;
    }
    else{
        head=tail=b;b=b->next;
    }
    while(a!=NULL&&b!=NULL){
        if(a->data<=b->data){
            tail->next=a;tail=a;a=a->next;
        }
        else{
            tail->next=b;tail=b;b=b->next;
        }
    }
    if(a==NULL){tail->next=b;}
    else{
        tail->next=a;
    }
    return head;
}


//For Leetcode submission
  ListNode *c = new ListNode(0);
        ListNode *head = c;
        while(a && b){
            if(a->val < b->val){
                c->next = new ListNode(a->val);
                a = a->next;
            }
            else{
                c->next = new ListNode(b->val);
                b = b->next;
            }
            c = c->next;
        }
        while(a){
            c->next = new ListNode(a->val);
            a = a->next;
            c = c->next;
        }
        while(b){
            c->next = new ListNode(b->val);
            b = b->next;
            c = c->next;
        }
        return head->next;        
    }

    //Optimized:
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
         if(l1==NULL)return l2;
        if(l2==NULL)return l1;
        if(l1->val>l2->val) swap(l1,l2);
        ListNode *res=l1;
        while(l1!=NULL && l2!=NULL){
            ListNode* temp=NULL;
            while(l1!=NULL && l1->val<=l2->val){
                temp=l1;
                l1=l1->next;
            }
            temp->next=l2;
            swap(l1,l2);
        }
        return res;
    }
};
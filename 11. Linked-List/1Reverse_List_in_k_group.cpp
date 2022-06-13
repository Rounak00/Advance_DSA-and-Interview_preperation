//Recursive
class Solution {
public:
    void reverse(ListNode* s, ListNode* e){
        ListNode*p=NULL,*c=s;
        while(p!=e){
          ListNode* n=c->next;
          c->next=p;  
          p=c;
          c=n;
            if(n!=NULL)n=n->next;
        }
        
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL||head->next==NULL||k==1){
            return head;
        }
        ListNode *e=head,*s=head; 
        int inc=k-1;
        while(inc--){
            e=e->next;
            if(e==NULL){return head;}
        }
        ListNode *nexhead=reverseKGroup(e->next,k);
        reverse(s,e);
        s->next=nexhead;
        return e;
    }
};

//Iterativ
class Solution {
public:
    void reverse(ListNode* s, ListNode* e){
        ListNode*p=NULL,*c=s;
        while(p!=e){
          ListNode* n=c->next;
          c->next=p;  
          p=c;
          c=n;
            if(n!=NULL)n=n->next;
        }
        
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL||head->next==NULL||k==1){
            return head;
        }
        ListNode *dummy=new ListNode(-1);
        dummy->next=head;
        ListNode *befs=dummy; 
        ListNode *e=head; 
        int inc=0;
        while(e!=NULL){
            inc++;
            if(inc%k==0){
                ListNode *s=befs->next;
                ListNode *temp=e->next;
                reverse(s,e);
                befs->next=e;
                s->next=temp;
                
                befs=s;
                e=temp;
            }else{
                e=e->next;
            }
        }
        return dummy->next;
    }
};  

//Striver
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || k==1)return head;
        
        ListNode *dummy=new ListNode(-1);
        dummy->next=head;
        
        ListNode *cur=dummy, *pre=dummy, *nex=dummy;
        
        int count=0;
        ListNode* c=head;
        while(c!=NULL){
           
            count++;
           c=c->next;
        }
        
        while(count>=k){
            cur=pre->next;
            nex=cur->next;
            for(int i=1;i<k;i++){
                cur->next=nex->next;
                nex->next=pre->next;
                pre->next=nex;
                nex=cur->next;
            }
            pre=cur;
            count-=k;
        }
        return dummy->next;
    }
};

//Naive:
bool isPalindrome(Node *head){
    stack<char> st;
    for(Node *curr=head;curr!=NULL;curr=curr->next)
        st.push(curr->data);
    for(Node *curr=head;curr!=NULL;curr=curr->next){
        if(st.top()!=curr->data)
            return false;
        st.pop();
    }
    return true;
}

//Efficient:

Node *reverseList(Node *head){
    if(head==NULL||head->next==NULL)return head;
    Node *rest_head=reverseList(head->next);
    Node *rest_tail=head->next;
    rest_tail->next=head;
    head->next=NULL;
    return rest_head;
}

bool isPalindrome(Node *head){
        if(head==NULL)return true;
        Node *slow=head,*fast=head;
        while(fast->next!=NULL&&fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        Node *rev=reverseList(slow->next);
        Node *curr=head;
        while(rev!=NULL){
            if(rev->data!=curr->data)
                return false;
            rev=rev->next;
            curr=curr->next;
        }
        return true;
    }

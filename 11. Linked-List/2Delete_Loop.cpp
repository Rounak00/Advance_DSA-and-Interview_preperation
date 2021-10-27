//Dummy node:

bool isLoop(Node* head) 
{   Node* temp=new Node(0);
    Node *curr=head;
    while (curr != NULL) {  
        if (curr->next==NULL)
            return false;
        if(curr->next==temp)
            return true;
        Node *curr_next=curr->next;
        curr->next=temp;
        curr=curr_next;
    } 
    return false; 
}

//Hashing:

bool isLoop(Node* head) 
{ 
    unordered_set<Node*> s; 
    for(Node *curr=head;curr!=NULL;curr=curr->next) {  
        if (s.find(curr) != s.end()) 
            return true; 
        s.insert(curr); 
    } 
    return false; 
}

//Floyd cycle detection:

bool isLoop(Node* head) 
{ 
    Node *slow_p = head, *fast_p = head; 
  
    while (fast_p!=NULL && fast_p->next!=NULL) { 
        slow_p = slow_p->next; 
        fast_p = fast_p->next->next; 
        if (slow_p == fast_p) { 
            return true; 
        } 
    } 
    return false; 
}
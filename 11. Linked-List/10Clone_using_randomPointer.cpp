//Hash Map
Node* clone(Node *head) 
{ 
    unordered_map<Node*,Node*> hm;
    for(Node *curr=head;curr!=NULL;curr=curr->next)
        hm[curr]=new Node(curr->data);
    
    for(Node *curr=head;curr!=NULL;curr=curr->next){
        Node *cloneCurr=hm[curr];
        cloneCurr->next=hm[curr->next];
        cloneCurr->random=hm[curr->random];
    }
    Node *head2=hm[head];
    
    return head2;
}

//Efficient:
Node* clone(Node *head) 
{ 
    Node *next,*temp;
    for(Node *curr=head;curr!=NULL;){
        next=curr->next;
        curr->next=new Node(curr->data);
        curr->next->next=next;
        curr=next;
    }
    for(Node *curr=head;curr!=NULL;curr=curr->next->next){
        curr->next->random=(curr->random!=NULL)?(curr->random->next):NULL;
    }
    
     Node* original = head, *copy = head->next; 
  
    temp = copy; 
  
    while (original && copy) 
    { 
        original->next = 
         original->next? original->next->next : original->next; 
  
        copy->next = copy->next?copy->next->next:copy->next; 
        original = original->next; 
        copy = copy->next; 
    } 
  
    return temp;   
}
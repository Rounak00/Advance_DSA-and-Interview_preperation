class Solution {
public:
 ListNode* merge(ListNode *l1, ListNode *l2)
    {
        ListNode *ptr = new ListNode(0);
        ListNode *curr = ptr;
        
        while(l1 != NULL && l2 != NULL)
        {
            if(l1->val <= l2->val)
            {
                curr -> next = l1;
                l1 = l1 -> next;
            }
            else
            {
                curr -> next = l2;
                l2 = l2 -> next;
            }
        
        curr = curr ->next;
        
        }
        
        //for unqual length linked list
        
        if(l1 != NULL)
        {
            curr -> next = l1;
            l1 = l1->next;
        }
        
        if(l2 != NULL)
        {
            curr -> next = l2;
            l2 = l2 ->next;
        }
        
        return ptr->next;
    }

ListNode* sortList(ListNode* head) 
{
    if(head == NULL || head -> next == NULL)
        return head;
    
    ListNode* slow = head;
    ListNode* fast = head -> next;  // Finding the middle point first
    
    while(fast && fast -> next)
    {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    
    ListNode* newHead = slow -> next;  // creating two seperate LL 
    slow -> next = NULL;   
    
    ListNode *m1=sortList(head);
    ListNode* m2=sortList(newHead);    
    return merge(m1,m2);
 }
};
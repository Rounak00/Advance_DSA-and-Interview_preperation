/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    class compare{
        public:
        bool operator()(ListNode* a,ListNode* b){
            return a->val>b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // min priority queue
       
        priority_queue<ListNode*, vector<ListNode*>,compare>q;
        
        for(int i = 0; i < lists.size(); i++)
            if(lists[i] != nullptr) 
                q.push(lists[i]);
        ListNode* dummy = new ListNode(0);
        ListNode* cursor = dummy;
        while(!q.empty()){
            ListNode* curr = q.top();
            q.pop();
            if(curr->next != nullptr) q.push(curr->next);
            cursor->next = curr;
            cursor = curr;
        }
        return dummy->next;
    }
};
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
 
        stack<int> st1 , st2;
        ListNode*ans = new ListNode(0);
        while(l1){
            st1.push(l1->val);
            l1 = l1->next;
        }
        while(l2){
            st2.push(l2->val);
            l2 = l2->next;
        }
        int sum = 0;
        while(!st1.empty() || !st2.empty()){
            if(!st1.empty()) {sum += st1.top(); st1.pop();}
            if(!st2.empty()) {sum += st2.top(); st2.pop();}
            ans->val = sum%10;
            sum/=10;
            ListNode* head = new ListNode(sum);            
            head->next = ans;
            ans = head;
        }
        return ans->val == 0? ans->next : ans;
    }

};
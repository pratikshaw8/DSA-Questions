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
    ListNode* swapPairs(ListNode* head) {
        
        if(head==NULL or head->next ==NULL)
            return head;
        
        ListNode*first=head;
        ListNode *second=first->next;
        
        
        first->next=second->next;
        second->next=first;
        
        
        first->next=swapPairs(first->next);
        return second;       
    }
};
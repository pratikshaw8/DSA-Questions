/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* floydDetection(ListNode*head)
    {
        if(head==NULL)
        return NULL;
    
    
         ListNode*slow=head;
         ListNode*fast=head;

        while(slow!=NULL and fast !=NULL)
        {
            fast=fast->next;
            if(fast!=NULL)
                fast=fast->next;
            else 
                break;
            slow=slow->next;
            if(slow==fast)
                return slow;
        }

        return NULL;
    }
    
    ListNode *detectCycle(ListNode *head) {
        
        if(head==NULL)
        return NULL;
    
        ListNode* intersection=floydDetection(head);
        if(intersection==NULL)
            return NULL;
        ListNode* small=head;
        while(small!=intersection)
        {
            small=small->next;
            intersection=intersection->next;
        }
        return small;
        
    }
};
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
    ListNode* getMid(ListNode *head)
    {
        ListNode*slow=head;
        ListNode*fast=head->next;
        
        while(fast!=NULL && fast->next !=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    
    ListNode* reverse(ListNode *head)
    {
        ListNode* temp=head;
        ListNode*prev=NULL;
        ListNode*next=NULL;
        
        while(temp!=NULL)
        {
            next=temp->next;
            temp->next=prev;
            prev=temp;
            temp=next;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL)
        return true;
        
        
        ListNode* middle=getMid(head);
        
        middle->next=reverse(middle->next);
        ListNode*temp=head;
        ListNode*temp2=middle->next;
        
        while(temp2!=NULL)
        {
            if(temp->val !=temp2->val)
            return false;
            temp=temp->next;
            temp2=temp2->next;
        }
        
        temp=middle->next;
        return true;
    }
};
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
    
    int len(ListNode*head)
    {
        ListNode* temp=head;
        int count=0;
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
        return count;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(head==NULL)
            return NULL;
        
        ListNode*curr=head;
        ListNode*next=NULL;
        ListNode*prev=NULL;
        int count=1;
        
        if(len(head) >=k )
        {
        
            while(curr!=NULL && count<=k)
            {
                next=curr->next;
                curr->next=prev;
                prev=curr;
                curr=next;
                count++;
            }

            if(next!=NULL)
            {
                head->next=reverseKGroup(next,k);
            }
            return prev;
        }
        
        else
        {
            return head;
        }
         
    }
};






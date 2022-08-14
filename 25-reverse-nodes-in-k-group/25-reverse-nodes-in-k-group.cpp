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
    int length(ListNode * head)
    {
        int len=0;
        ListNode * temp=head;
        while(temp)
        {
            len++;
            temp=temp->next;
        }
        return len;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(head ==NULL)
            return head;
        int count=1;
            ListNode* temp=head;
            ListNode *prev=NULL, *nxt=NULL;
        if(length(head) >=k)
        {
            
            while(temp and count<=k)
            {
                nxt=temp->next;
                temp->next= prev;
                
                prev=temp;
                temp=nxt;
                count++;
            }
            
            if(nxt)
                head->next = reverseKGroup(nxt,k);
            return prev;
                
        }
        else
            return head;
    }
};
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(head==NULL or head->next==NULL or left==right)
            return head;
        
        ListNode* tempHead=new ListNode(501);
        ListNode*ans=tempHead;
        ListNode *tempTail=tempHead;
        tempHead->next=head;
        int i;
        for(i=0;i<left-1;i++)
        {
            tempHead=tempHead->next;
            tempTail=tempTail->next;
        }

        for( ; i<=right;i++)
        {
            tempTail=tempTail->next;
        }
        
        
        
        ListNode* rev=tempHead->next;
                
        
        // for(int i=0;i<left-1;i++)
        //     rev=rev->next;
        
        ListNode* curr;
        ListNode*prev=NULL;
        ListNode*next=NULL;
        for(int i=left;i<=right;i++)
        {
            if(rev!=NULL)
            {
                next=rev->next;
                if(prev!=NULL)
                    rev->next=prev;
                else
                    rev->next=tempTail;
                prev=rev;
                rev=next;
            }
            
        }
        
        tempHead->next->next=rev;
        tempHead->next=prev;
        
        return ans->next;
            
    }
};





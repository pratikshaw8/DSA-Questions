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
    
    
    int length(ListNode *head)
    {
        int c=0;
        ListNode *temp=head;
        while(temp!=NULL)
        {
            c++;
            temp=temp->next;
        }
        return c;
    }
    
    ListNode* middleNode(ListNode* head) {
        
        int leng= length(head);
        ListNode *temp=head;
        int middle=leng/2+1;
        
        while(middle>1)
        {
            temp=temp->next;
            middle--;
        }
        
        
        return temp;
            
    }
};
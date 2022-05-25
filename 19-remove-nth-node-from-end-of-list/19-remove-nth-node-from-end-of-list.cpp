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
    int length(ListNode* head)
    {
        int c=0;
        while(head!=NULL)
        {
            c++;
            head=head->next;
        }
        return c;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int len=length(head);
        int k=len-n;
        if(head==NULL)
            return head;
        if(n==len)
            return head->next;
        
        ListNode*temp=head;
        while(temp!=NULL)
        {
            if(k==1)
            {
                temp->next=temp->next->next;
                temp=temp->next;
                break;
            }
            k--;
            temp=temp->next;
        }
        
        return head;
    }
};












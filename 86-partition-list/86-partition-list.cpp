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
    ListNode* partition(ListNode* head, int x) {
        
        if(head==NULL or head->next==NULL )
            return head;
        
        ListNode* l1=new ListNode(-101);
        ListNode* l2=new ListNode(-101);
        ListNode *ptr1=l1;
        ListNode* ptr2=l2;
        
        while(head!=NULL)
        {
            ListNode *curr=new ListNode(head->val);
            if(head->val < x)
            {
                ptr1->next=curr;
                ptr1=ptr1->next;
            }
            else
            {
                ptr2->next=curr;
                ptr2=ptr2->next;
            }
            head=head->next;
            
        }
        if(ptr1->val==-101)
        {
            return l2->next;
        }
        else if(ptr2->val == -101)
        {
            return l1->next;
        }
        
        l1=l1->next;
        ptr1->next=l2->next;
        return l1;
        
    }
};
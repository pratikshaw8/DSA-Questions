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
        if(head == NULL){
            return 0;
        }
        
        return 1 + length(head->next);
    }
    ListNode* reverse(ListNode* head, int k,int size)
    {
        if(head ==NULL)
            return NULL;
        if(size < k)
            return head;
        
        int count=1;
        ListNode* temp=head;
        ListNode *prev=NULL, *nxt=NULL;
        
        while(temp and count<=k)
        {
            nxt= temp->next;
            temp->next = prev;
            prev=temp;
            temp=nxt;
            count++;
        }
        
        head->next = reverse(nxt,k,size-k);
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {

        int a = length(head);
        return reverse(head,k,a);
        
    }
};
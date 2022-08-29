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
    int length(ListNode* h)
    {
        int c=0;
        while(h!=NULL)
        {
            h=h->next;
            c++;
        }
        return c;
    }
    ListNode* rotateRight(ListNode* &head, int k) {
        if(head == NULL or head->next == NULL) return head;
        int len=length(head);
        k=k%len;
        if(k==0)
            return head;
        ListNode *temp=head;
        
        int i=0;
        while(i < len-k-1)
        {
            temp=temp->next;
            i++;
        }
        ListNode *tmp=temp->next;
        temp->next=NULL;
        
        ListNode* q=tmp;
        while(q->next !=NULL)
        {
            q=q->next;
        }
        
        q->next = head;
        head=tmp;
        return head;
        
    }
};










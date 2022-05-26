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
    ListNode* rotateRight(ListNode* &head, int k) {
        
        if(head==NULL or head->next==NULL)
            return head;
        ListNode*tmp=head;
        int len=length(head);
        
        k=k%len;
        int p=0;
        if(k==0)
            return head;
        
        while(p<(len-k-1))
        {
            tmp=tmp->next;
            p++;
        }
        
        ListNode*temp=tmp->next;
        tmp->next=NULL;
        
        ListNode* q=temp;
        while(q->next!=NULL)
        {
            q=q->next;
            
        }
        
        q->next=head;
        head=temp;
        
        return head;
        
        
        
        
    }
};
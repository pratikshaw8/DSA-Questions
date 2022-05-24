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
#include<unordered_map>
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        unordered_map<int,int> m;
        
        
        ListNode* t =head;
        while(t!=NULL)
        {
            m[t->val]++;
            t=t->next;
        }
    
        ListNode* temp=new ListNode(101);
        temp->next=head;
        ListNode*prev=temp;
        t=temp;
        temp=temp->next;
        while(temp!=NULL)
        {
            
            if(m[temp->val]>1)
            {
                prev->next=temp->next;
                temp=temp->next;
                continue;
                
            }
            prev=temp;
            temp=temp->next;
            
                
            
        }
        return t->next;
    }
};





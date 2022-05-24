/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include<unordered_map>
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*,bool> m;
        ListNode*temp=head;
        
        if(head==NULL)
            return false;
        else if(head->next==NULL)
            return false;
        else if(head->next==head)
            return true;
        
        while(temp->next!=NULL)
        {
            if(m[temp->next]==true)
            {
                return true;
            }
            m[temp]=true;
            temp=temp->next;
        }
        return false;
        
    }
};
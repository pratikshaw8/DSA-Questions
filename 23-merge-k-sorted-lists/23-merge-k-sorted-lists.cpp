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
#include<queue>
class compare{
    public:
    bool operator()(ListNode* a, ListNode* b)
    {
        if(a && b)
        return a->val > b->val;
        return false;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<ListNode*, vector<ListNode*>, compare> minheap;
        int i;
        for(i=0;i<lists.size();i++)
        {
            if(lists[i]!=NULL)
            minheap.push(lists[i]);
        }
        
        ListNode* ans=new ListNode(-1);
        ListNode* res=ans;
        
        while(minheap.size() != 0)
        {
            ListNode *temp=minheap.top();
            minheap.pop();
            if(temp==NULL)
                break;
            
            ans->next=temp;
            ans=ans->next;
            
            
            if( temp->next!=NULL)
            {
                minheap.push(temp->next);
            }
            
        }
        
        return res->next;
        
        
    }
};




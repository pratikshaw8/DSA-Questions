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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
         ListNode* final=new ListNode(-1);
        ListNode* head=final;
        while(list1!=NULL and list2!=NULL)
        {
            if(list1->val <= list2->val)
            {
                ListNode* newNode=new ListNode(list1->val);
                final->next=newNode;
                list1=list1->next;
            }
            else
            {
                ListNode* newNode=new ListNode(list2->val);
                final->next=newNode;
                list2=list2->next;
            }
            final=final->next;

        }
        while(list1!=NULL)
        {
            ListNode* newNode=new ListNode(list1->val);
            final->next=newNode;
            list1=list1->next;
            final=final->next;
        }
        while(list2!=NULL)
        {
            ListNode* newNode=new ListNode(list2->val);
            final->next=newNode;
            list2=list2->next;
            final=final->next;
        }

        return head->next;
    }
};
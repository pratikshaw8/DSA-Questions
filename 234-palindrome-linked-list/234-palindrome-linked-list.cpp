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
    ListNode * reverse(ListNode* head)
    {
        ListNode * rev=head,*prev=NULL, *nxt=head->next;
        
        while(rev)
        {
            nxt=rev->next;
            rev->next= prev;
            prev=rev;
            rev=nxt;
        }
        return prev;
    }
    bool checkIsPalindrome(ListNode *first , ListNode * second)
    {
        while(first and second)
        {
            if(first->val != second->val ) return false;
            first=first->next;
            second=second->next;
        }
        if(first or second) return false;
        return true;
    }
    bool isPalindrome(ListNode* head) {
        if(!head or !head->next)
            return true;
        
        ListNode *slow =head,*fast=head;
        
        while(fast->next and fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *secondList=slow->next;
        if(!fast->next)
        {
            slow->next= NULL;
            ListNode *firstList= reverse(head)->next;
            return checkIsPalindrome(firstList,secondList);
        }
        slow->next=NULL;
        return checkIsPalindrome(secondList, reverse(head));
    }
};
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
    bool checkIsPalindrome(ListNode* first, ListNode* second) {
        while(first && second) {
            if(first->val!=second->val) return false;
            first = first->next;
            second = second->next;
        }
        if(first || second) return false;
        return true;
    }
    
    ListNode* reverse(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* first = head;
        ListNode* second = head->next;
        ListNode* third = second?second->next:nullptr;
        first->next = nullptr;
        while(second) {
            second->next = first;
            first = second;
            second = third;
            third = third?third->next:nullptr;
        }
        return first;
    }
    
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* secondList = slow->next;
        if(!fast->next) {
            slow->next = nullptr;
            ListNode* firstList = (reverse(head))->next;
            return checkIsPalindrome(firstList, secondList);
        }
        slow->next = nullptr;
        return checkIsPalindrome(secondList, reverse(head));
    }
};
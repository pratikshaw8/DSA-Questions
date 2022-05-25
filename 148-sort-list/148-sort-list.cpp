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
    
    ListNode *getMid(ListNode *head)
    {
        ListNode* slow=head;
        ListNode *fast=head->next;
        while(fast!=NULL and fast->next !=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    ListNode *merge(ListNode *left, ListNode *right)
    {
        if(left==NULL)
            return right;
        if(right==NULL)
            return left;

        ListNode *ans=new ListNode(-1);
        ListNode *temp=ans;

        while(left!=NULL && right !=NULL){

            if(left->val <= right->val)
            {
                ListNode *newNode=new ListNode(left->val);
                temp->next=newNode;
                left=left->next;
            }
            else
            {
                ListNode *newNode=new ListNode(right->val);
                temp->next=newNode;
                right=right->next;
            }
            temp=temp->next;
        }
        while(left!=NULL)
        {
            ListNode *newNode=new ListNode(left->val);
            temp->next=newNode;
            left=left->next;
            temp=temp->next;
        }
        while(right!=NULL)
        {
            ListNode *newNode=new ListNode(right->val);
            temp->next=newNode;
            right=right->next;
            temp=temp->next;
        }
        return ans->next;
    }

    
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }

        ListNode *mid=getMid(head);

        ListNode* left=head;
        ListNode *right= mid->next;
        mid->next=NULL;


        //recursive calls
        left=sortList(left);
        right=sortList(right);

        ListNode*result= merge(left,right);

        return result;
    }
};
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
//     struct Node* reverse(struct Node* head)
//     {
//         struct Node* temp=head;
//         struct Node*prev=NULL;
//         struct Node* next=NULL;
        
//         while(temp!=NULL)
//         {
//             next=temp->next;
//             temp->next=prev;
//             prev=temp;
//             temp=next;
//         }
//         return prev;
//     }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
         // code here
        
        
        ListNode* sumList=new ListNode(-1);
        ListNode*ans=sumList;
        
        int carry=0,sum=0;
        
        while(l1!=NULL and l2!=NULL)
        {
            sum=(l1->val + l2->val +carry)%10 ;
            carry=(l1->val + l2->val +carry)/10;
            ListNode* newNode=new ListNode(sum);
            sumList->next=newNode;
            sumList=sumList->next;
            l1=l1->next;
            l2=l2->next;
            
        }
        while(l1!=NULL)
        {
            sum=(l1->val +carry)%10 ;
            carry=(l1->val +carry)/10;
            l1=l1->next;
            ListNode* newNode=new ListNode(sum);
            sumList->next=newNode;
            sumList=sumList->next;
        }
        while(l2!=NULL)
        {
            sum=(l2->val +carry)%10 ;
            carry=(l2->val +carry)/10;
            l2=l2->next;
            ListNode* newNode=new ListNode(sum);
            sumList->next=newNode;
            sumList=sumList->next;
        }
        if(carry>0)
        {
            ListNode *newNode=new ListNode(carry);
            sumList->next=newNode;
            sumList=sumList->next;
        }
        ans=ans->next;
        
        return ans;
    }
};
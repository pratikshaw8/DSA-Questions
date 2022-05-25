// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




 // } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
#include<algorithm>

class Solution{
  public:
  
    Node* getMid(Node *head)
    {
        Node*slow=head;
        Node*fast=head->next;
        
        while(fast!=NULL && fast->next !=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    
    Node* reverse(Node *head)
    {
        Node* temp=head;
        Node*prev=NULL;
        Node*next=NULL;
        
        while(temp!=NULL)
        {
            next=temp->next;
            temp->next=prev;
            prev=temp;
            temp=next;
        }
        return prev;
    }
    
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here
        if(head->next==NULL)
        return true;
        
        
        Node* middle=getMid(head);
        
        middle->next=reverse(middle->next);
        Node*temp=head;
        Node*temp2=middle->next;
        
        while(temp2!=NULL)
        {
            if(temp->data !=temp2->data)
            return false;
            temp=temp->next;
            temp2=temp2->next;
        }
        
        temp=middle->next;
        return true;
        
    }
};



// { Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}

  // } Driver Code Ends
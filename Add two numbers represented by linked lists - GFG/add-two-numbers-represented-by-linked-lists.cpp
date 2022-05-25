// { Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    
    struct Node* reverse(struct Node* head)
    {
        struct Node* temp=head;
        struct Node*prev=NULL;
        struct Node* next=NULL;
        
        while(temp!=NULL)
        {
            next=temp->next;
            temp->next=prev;
            prev=temp;
            temp=next;
        }
        return prev;
    }
    
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        first=reverse(first);
        second=reverse(second);
        
        struct Node* sumList=new Node(-1);
        struct Node*ans=sumList;
        
        int carry=0,sum=0;
        
        while(first!=NULL and second!=NULL)
        {
            sum=(first->data + second->data +carry)%10 ;
            carry=(first->data + second->data +carry)/10;
            struct Node* newNode=new Node(sum);
            sumList->next=newNode;
            sumList=sumList->next;
            first=first->next;
            second=second->next;
            
        }
        while(first!=NULL)
        {
            sum=(first->data +carry)%10 ;
            carry=(first->data +carry)/10;
            first=first->next;
            struct Node* newNode=new Node(sum);
            sumList->next=newNode;
            sumList=sumList->next;
        }
        while(second!=NULL)
        {
            sum=(second->data +carry)%10 ;
            carry=(second->data +carry)/10;
            second=second->next;
            struct Node* newNode=new Node(sum);
            sumList->next=newNode;
            sumList=sumList->next;
        }
        if(carry>0)
        {
            struct Node *newNode=new Node(carry);
            sumList->next=newNode;
            sumList=sumList->next;
        }
        ans=ans->next;
        ans=reverse(ans);
        return ans;
        
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends
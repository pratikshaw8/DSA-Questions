// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    
    Node* reverse(Node * head)
    {
        Node *temp=head;
        Node *next=NULL;
        Node *prev=NULL;
        while(temp!=NULL)
        {
            next=temp->next;
            temp->next=prev;
            prev=temp;
            temp=next;
        }
        return prev;
    }
    
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        
        Node *temp=reverse(head);
        Node*ans=temp;
        int sum=(temp->data +1 ) % 10;
        int carry=(temp->data +1) / 10;
        
        temp->data=sum;
        temp=temp->next;
        
        
        while(carry!=0 && temp!=NULL)
        {
            
            
            sum=(temp->data + carry ) % 10;
            carry=(temp->data +carry)/10;
            temp->data=sum;
            temp=temp->next;
            
        }
        
        
        
        
        temp=reverse(ans);
        
        if(carry>0)
        {
            Node* newNode=new Node(carry);
            carry=0;
            newNode->next=temp;
            temp=newNode;
        }
        
        
        return temp;
        
        
        
    }
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 
  // } Driver Code Ends
// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k);
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        queue<int> ans = modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}// } Driver Code Ends


// User function Template for C++

void modify(queue<int> &q,int k,int n,deque<int>& dq)
{
    if(q.empty())
    return ;
    

    if(k>0)
    {
        int ele=q.front();
        q.pop();
        dq.push_front(ele);
        modify(q,k-1,n-1,dq);
    }
    else
    {
        int ele=q.front();
        q.pop();
        dq.push_back(ele);
        modify(q,k-1,n-1,dq);
    }
    
    
    
    
    
    
}

// Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k) {
    // add code here
    
    deque<int> dq;
    
    modify(q,k,q.size(),dq);
    
    while(!dq.empty())
    {
        q.push(dq.front());
        dq.pop_front();
    }
    return q;
    
}
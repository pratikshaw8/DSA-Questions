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

void firstK(queue<int>&q,int k)
{
    if(k==0)
    return;
    
    int ele=q.front();
    q.pop();
    firstK(q,k-1);
    q.push(ele);
}

// Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k) {
    // add code here
    
    firstK(q,k);
    
    int t=q.size()-k;
    while(t>0)
    {
        int ele=q.front();
        q.pop();
        q.push(ele);
        t--;
    }
    
    return q;
    
}
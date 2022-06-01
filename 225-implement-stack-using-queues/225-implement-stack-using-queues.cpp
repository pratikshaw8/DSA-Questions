class MyStack {
public:
    
    queue<int> q;
    
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        for(int i=0;i<q.size()-1;i++)
        {
            int val=q.front();
            q.pop();
            q.push(val);
        }
        
    }
    
    int pop() {
        
        if(q.empty())
            return -1;
        
        int val=q.front();
        q.pop();
        return val;
    }
    
    int top() {
        
        return q.empty() ? -1 : q.front();
    }
    
    bool empty() {
        
        return q.empty();
        
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
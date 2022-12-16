class MyQueue {
public:
    stack<int> st;
    stack<int> st2;
    MyQueue() {
        
    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        if(st2.empty())
        {
            while(!st.empty())
            {
                st2.push(st.top());
                st.pop();
            }  
        }
        int top=st2.top();
        st2.pop();
        return top;
    }
    
    int peek() {
        if(st2.empty())
        {
            while(!st.empty())
            {
                st2.push(st.top());
                st.pop();
            }  
        }
        return st2.top();
    }
    
    bool empty() {
        if(st2.empty() and st.empty())return true;
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
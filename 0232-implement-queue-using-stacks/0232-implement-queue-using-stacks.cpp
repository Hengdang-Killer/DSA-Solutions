class MyQueue {
public:
    stack<int> st1, st2;
    MyQueue() 
    {
        
    }
    
    void push(int x) 
    {
        st2.push(x);    
    }
    
    int pop() 
    {
        if(st1.empty() && st2.empty())
            return NULL;
        if(st1.empty())
        {
            while(!st2.empty())
            {
                st1.push(st2.top());
                st2.pop();
            }
        }
        int val = st1.top();
        st1.pop();
        return val;        
    }
    
    int peek() 
    {
        if(st1.empty() && st2.empty())
            return NULL;
        if(st1.empty())
        {
            while(!st2.empty())
            {
                st1.push(st2.top());
                st2.pop();
            }
        }
        return st1.top();  
    }
    
    bool empty() 
    {
        if(st1.empty() && st2.empty())
            return true;
        return false;
    }
};

auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
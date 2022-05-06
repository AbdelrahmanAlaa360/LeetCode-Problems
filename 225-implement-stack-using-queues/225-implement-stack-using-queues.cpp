class MyStack {
public:    
    queue<int>q; 
    int peek = 0;
    
    MyStack() {  
        
    }    
    
    void push(int x) {
        peek = x;
        q.push(x);        
    }    
    
    int pop() {      
        int n = q.size() - 1;               
        while(n--){           
            peek = q.front(); 
            q.push(peek);
            q.pop();
        }         
        int ret = q.front();     
        q.pop();                        
        return ret;
    }    
    
    int top() {
        return peek;    
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
class MinStack {
public:
   stack<pair<int,int>>st;

    
    void push(int value) {
        if(st.empty()){
            st.push({value,value});
        }
        else{
            st.push({value,min(value,getMin())});
        }
    }
    
    void pop() {
        if(!st.empty()){
            st.pop();
        }    }
    
    int top() {
       if(st.empty()) return -1;
       else{
        return st.top().first;
       } 
    }
    
    int getMin() {
        if(st.empty()) return -1;
      
        return st.top().second;
       
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
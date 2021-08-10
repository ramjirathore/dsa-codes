// PROBLEM -

// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

// Implement the MinStack class:

// MinStack() initializes the stack object.
// void push(val) pushes the element val onto the stack.
// void pop() removes the element on the top of the stack.
// int top() gets the top element of the stack.
// int getMin() retrieves the minimum element in the stack.

// LINK - https://leetcode.com/problems/min-stack/

// Using another stack
class MinStack {
    stack<int> s1;
    stack<int> s2;
public:
   
    void push(int val) {
        if(s2.empty() or val <= s2.top()) s2.push(val);
        s1.push(val);
    }
    
    void pop() {
        if(s2.top() == s1.top()) s2.pop();
        s1.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
       return s2.top(); 
    }
};


// Using stack of pairs
// vector could be used if stack not allowed
class MinStack {
    stack<pair<int,int>> s;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int val) {
        int curr_min;
        
        if(s.empty()) curr_min = val;
        else curr_min = min(s.top().second, val);
        
        s.push({val, curr_min});
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }
};
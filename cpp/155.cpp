#include<bits/stdc++.h>
using std::vector;

class MinStack {
public:
    vector<int>* stack;
    vector<int>* min_stack;
    /** initialize your data structure here. */
    MinStack() {
        stack = new vector<int>();
        min_stack = new vector<int>();
        min_stack->push_back(INT_MAX);
    }
    
    void push(int x) {
        stack->push_back(x);
        int pre_min = min_stack->back();
        if (x < pre_min) 
            min_stack->push_back(x);     
        else
            min_stack->push_back(pre_min);
    }
    
    void pop() {
        stack->pop_back();
        min_stack->pop_back();
    }
    
    int top() {
        return stack->back();
    }
    
    int getMin() {
        return min_stack->back();
    }
};

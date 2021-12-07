#include <stack>
using namespace std;

class MinStack {
public:
    stack<int> stk, stk1;
    MinStack() {
        
    }
    
    void push(int x) {
        stk.push(x);
        if (stk1.empty() || x <= stk1.top()) stk1.push(x);
    }
    
    void pop() {
        if (stk.top() == stk1.top()) stk1.pop();
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return stk1.top();
    }
};
class MinStack {
public:
    vector<int> minStack;
    stack<int> st;

    MinStack() {}

    void push(int val) {
        if (st.empty()) {
            minStack.push_back(val);
        } else {
            minStack.push_back(min(minStack.back(), val));
        }

        st.push(val);
    }

    void pop() {
        st.pop();
        minStack.pop_back();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minStack.back();
    }
};
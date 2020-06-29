class MinStack {
public:
    /** initialize your data structure here. */
    
      stack<pair<int, int>> st;

public:
    void push(int x) {
        int min;
        if (st.empty()) {
            min = x;
        }
        else {
            min = std::min(st.top().second,x);
        }
        st.push({x, min});
    }

    void pop() {
        st.pop();
    }

    int top() {
        return st.top().first;
    }

    int getMin() {
        return st.top().second;
    }
};

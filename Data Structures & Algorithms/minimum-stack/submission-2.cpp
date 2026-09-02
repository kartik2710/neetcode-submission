class MinStack {
public:
    stack<long long> st;
    long long minEle;

    MinStack() {
        minEle = 0;
    }

    void push(int val) {
        if (st.empty()) {
            st.push(val);
            minEle = val;
        }
        else if (val >= minEle) {
            st.push(val);
        }
        else {
            st.push(2LL * val - minEle);
            minEle = val;
        }
    }

    void pop() {
        if (st.empty()) return;

        long long top = st.top();
        st.pop();

        if (top < minEle) {
            minEle = 2LL * minEle - top;
        }
    }

    int top() {
        if (st.empty()) return -1;

        long long top = st.top();

        if (top < minEle)
            return (int)minEle;

        return (int)top;
    }

    int getMin() {
        if (st.empty()) return -1;

        return (int)minEle;
    }
};
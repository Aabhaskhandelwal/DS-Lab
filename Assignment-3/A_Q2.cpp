#include <iostream>
using namespace std;

#define MAX 100  // maximum size of stack

class MinStack {
    long long arr[MAX];
    int topIndex;
    long long minEle;

public:
    MinStack() {
        topIndex = -1;
    }

    void push(int x) {
        if (topIndex == -1) {
            arr[++topIndex] = x;
            minEle = x;
        } else {
            if (x < minEle) {
                // store encoded value
                arr[++topIndex] = 2LL*x - minEle;
                minEle = x;
            } else {
                arr[++topIndex] = x;
            }
        }
    }

    void pop() {
        if (topIndex == -1) return;

        long long t = arr[topIndex--];

        if (t < minEle) {
            // decode previous min
            minEle = 2*minEle - t;
        }
    }

    int top() {
        if (topIndex == -1) return -1;

        long long t = arr[topIndex];
        if (t < minEle) return minEle;
        else return t;
    }

    int getMin() {
        if (topIndex == -1) return -1;
        return minEle;
    }
};

int main() {
    MinStack st;
    st.push(3);
    st.push(5);
    cout << "Min: " << st.getMin() << endl; // 3
    st.push(2);
    st.push(1);
    cout << "Min: " << st.getMin() << endl; // 1
    st.pop();
    cout << "Min: " << st.getMin() << endl; // 2
    st.pop();
    cout << "Top: " << st.top() << endl;    // 5
    cout << "Min: " << st.getMin() << endl; // 3
	
    return 0;
}


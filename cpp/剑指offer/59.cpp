#include <queue>
#include <deque>
#include <cstdio>
using std::printf;
using std::queue;
using std::deque;
class MaxQueue {
    /**
     * 132 ms, 在所有 C++ 提交中击败了97.64%
     * 51.5 MB, 在所有 C++ 提交中击败了100.00%
    */
public:
    std::queue<int> *q;
    std::deque<int> *dq;    
    int max;
    MaxQueue() {
        q = new queue<int>();
        dq = new deque<int>();
        max = 0;
    }
    
    int max_value() {
        // printf("-%d-", s->top());
        if (q->size())
            return dq->front();
        return -1;
    }
    
    void push_back(int value) {
        q->push(value);
        while (dq->size() && dq->back() < value) {
            dq->pop_back();
        }
        dq->push_back(value);
    }
    
    int pop_front() {
        if (q->size()) {
            int rs = q->front();
            q->pop();
            if (rs  == dq->front())
                dq->pop_front();
            return rs;
        }
        return -1;
    }
    ~MaxQueue() {
        if (q)
            delete q;
        if (dq)
            delete dq;

    }
};
/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */

int main()
{
    MaxQueue s;
    // printf("MaxQueue s: %d \n", s.max_value());
    printf("maxqueue : %d \n", s.max_value());
    printf("pop_front : %d \n", s.pop_front());
    printf("pop_front : %d \n", s.pop_front());
    s.push_back(94);
    s.push_back(16);
    s.push_back(89);
    printf("pop_front : %d \n", s.pop_front());
    s.push_back(22);
    printf("pop_front : %d \n", s.pop_front());


    // ["MaxQueue","max_value","pop_front","pop_front",
    // "push_back","push_back","push_back",
    // "pop_front","push_back","pop_front"]
// [[],[],[],[],[94],[16],[89],[],[22],[]]
}

#include <cstdlib>
#include <limits>
#include <cassert>

struct IntAbstractQueue {
    virtual void push(int x) = 0;
    virtual int pop() = 0;
    virtual bool is_empty() const = 0;
    virtual bool is_full() const = 0;

    virtual ~IntAbstractQueue() { }
};

struct IntStack: IntAbstractQueue {
    void push(int x) override {
        data[top++] = x;
    }
    int pop() override {
        return data[--top];
    }
    bool is_empty() const override {
        return 0 == top;
    }
    bool is_full() const override {
        return 10 == top;
    }
private:
    unsigned top = 0;
    int data[10];
};


class IntStackWithMax : public IntStack
{
    IntStack local;
    IntStack max_data;
public:
    IntStackWithMax() : IntStack(), max_data() {}

    void push(int x) override {
        if (x > get_max())
        {
            max_data.push(x);
        }
        return IntStack::push(x);
    }
    int pop() override {
        int poped = IntStack::pop();
        if (poped == get_max())
        {
            max_data.pop();
        }
        return poped;
    }
    bool is_empty() const override {
        return IntStack::is_empty();
    }
    bool is_full() const override {
        return IntStack::is_full();
    }
    int get_max() {
        if (max_data.is_empty())
        {
            return std::numeric_limits<int>::min();
        }
        int maximum = max_data.pop();
        max_data.push(maximum);
        return maximum;
    }
};

#include <cassert>
void with_queue_do(IntAbstractQueue &q) {
    assert(q.is_empty());
    q.push(1);
    assert(!q.is_empty());
    assert(1 == q.pop());
    assert(q.is_empty());
    for (int cnt = 0; cnt != 10; ++cnt)
        q.push(cnt);
    assert(q.is_full());
}
void with_stack_do(IntStack &s) {
    with_queue_do(s); 
    for (int cnt = 10; cnt != 0; --cnt)
        assert(cnt - 1 == s.pop());
    assert(s.is_empty());
}
void with_stackwithmax_do(IntStackWithMax &swm) {
    with_queue_do(swm);
    for (int cnt = 10; cnt != 0; --cnt)
        assert(cnt - 1 == swm.get_max() and cnt - 1 == swm.pop());
    assert(swm.is_empty()); 
}

int main() {
    IntStackWithMax swm;
    with_stack_do(swm);
    with_stackwithmax_do(swm);
    return 0;
}
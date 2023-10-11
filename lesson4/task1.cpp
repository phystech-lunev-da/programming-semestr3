#include <limits>

struct IntAbstractQueue {
    virtual void push(int x) = 0;
    virtual int pop() = 0;
    virtual int peek() const = 0;
    virtual bool is_empty() const = 0;
    virtual bool is_full() const = 0;

    virtual ~IntAbstractQueue() { }
};

struct IntStack final: IntAbstractQueue {
    void push(int x) override {
        data[top++] = x;
    }
    int pop() override {
        return data[--top];
    }
    int peek() const override {
        return data[top - 1];
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

class IntStackWithMax : public IntAbstractQueue
{
    mutable IntStack local;
    IntStack max_data;
public:
    IntStackWithMax() : IntAbstractQueue(), max_data() {}

    void push(int x) override {
        if (max_data.is_empty() || x > max_data.peek())
        {
            max_data.push(x);
        }
        return local.push(x);
    }
    int pop() override {
        if (local.peek() == max_data.peek())
        {
            max_data.pop();
        }
        return local.pop();
    }
    int peek() const override {
        return local.peek();
    }
    bool is_empty() const override {
        return local.is_empty();
    }
    bool is_full() const override {
        return local.is_full();
    }
    int get_max() const {
        return max_data.peek();
    }
};

#include <cassert>
void with_queue_do(IntAbstractQueue &q) {
    assert(q.is_empty());
    q.push(1);
    assert(!q.is_empty());
    assert(1 == q.peek());
    assert(!q.is_empty());
    assert(1 == q.pop());
    assert(q.is_empty());
    for (int cnt = 0; cnt != 10; ++cnt)
        q.push(cnt);
    assert(q.is_full());
}
void with_stackwithmax_do(IntStackWithMax &swm) {
    with_queue_do(swm);
    for (int cnt = 10; cnt != 0; --cnt)
        assert(cnt - 1 == swm.get_max() and cnt - 1 == swm.pop());
    assert(swm.is_empty()); 
}

int main() {
    IntStackWithMax swm;
    with_stackwithmax_do(swm);
    return 0;
}


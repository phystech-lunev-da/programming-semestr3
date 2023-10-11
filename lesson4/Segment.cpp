
#include <algorithm>

struct SegmentAbstract {
    virtual int beg() const = 0;
    virtual int end() const = 0;

    virtual ~SegmentAbstract() { }
};


struct SegmentSimple final: SegmentAbstract {
    int beg() const override { return _beg; }
    int end() const override { return _end; }
    SegmentSimple(int beg, int end): _beg(beg), _end(end) { }
private:
    int const _beg, _end;
};


struct SegmentSumm final: SegmentAbstract {

    SegmentSumm() : _beg(1), _end(0) {}

    SegmentSumm(SegmentAbstract const * left, SegmentAbstract const * right)
    {
        if (left->beg() > left->end())
        {
            _beg = right->beg();
            _end = right->end();
        }
        else if (right->beg() > right->end())
        {
            _beg = left->beg();
            _end = left->end();
        }
        else
        {
            _beg = std::min(left->beg(), right->beg()); 
            _end = std::max(left->end(), right->end()); 
        }
    }

    int beg() const override {
        return _beg;
    }
    
    int end() const override {
        return _end;
    }
private:
    int _beg, _end;
};

struct SegmentMultiply final: SegmentAbstract {

    SegmentMultiply() : _beg(1), _end(0) {}

    SegmentMultiply(SegmentAbstract const * left, SegmentAbstract const * right)
    {
        if (left->beg() > left->end() || right->beg() > right->end())
        {
            _beg = 1;
            _end = 0;
        }
        _beg = std::max(left->beg(), right->beg()); 
        _end = std::min(left->end(), right->end());
    }


    int beg() const override {
        return _beg;
    }
    
    int end() const override {
        return _end;
    }
private:
    int _beg, _end;
};

#include <cassert>

int main() {
    SegmentAbstract const *s1 = new SegmentSimple(1, 10);
    SegmentAbstract const *s2 = new SegmentSimple(5, 15);
    SegmentAbstract const *e  = new SegmentSimple(25, 20);

    SegmentAbstract const *summ_s1_s2 = new SegmentSumm(s1, s2);
    SegmentAbstract const *mult_s1_s2 = new SegmentMultiply(s1, s2);
    SegmentAbstract const *summ_s1_e = new SegmentSumm(s1, e);
    SegmentAbstract const *mult_s1_e = new SegmentMultiply(s1, e);
    
    assert(1 == summ_s1_s2->beg() and 15 == summ_s1_s2->end());
    assert(5 == mult_s1_s2->beg() and 10 == mult_s1_s2->end());
    assert(1 == summ_s1_e->beg() and 10 == summ_s1_e->end());
    assert(mult_s1_e->beg() > mult_s1_e->end());
    
    delete mult_s1_e;
    delete summ_s1_e;
    delete mult_s1_s2;
    delete summ_s1_s2;
    delete e;
    delete s2;
    delete s1;
    return 0;
}
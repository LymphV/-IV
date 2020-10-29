#include <LymphV>

class IntSet
{
    int v;
public:
    IntSet (int v) : v(v) {}

    class iterator
    {
        int v;
        int now;
    public:
        iterator (int value, int nowPos = 0) : v(value), now(nowPos)
        {
            for (; v; v >>= 1, ++now)
                if (v & 1) break;
        }

        bool operator== (iterator it) const
        {
            return v == it.v && (!v || now == it.now);
        }
        bool operator!= (iterator it) const
        {
            return !(*this == it);
        }


        iterator & operator++ ()
        {
            for(v >>= 1, ++now; v; v >>= 1, ++now)
                if (v & 1) break;
            return *this;
        }

        iterator operator++ (int)
        {
            iterator rst(v, now);
            ++*this;
            return rst;
        }

        int operator* ()
        {
            return now;
        }
    };

    iterator begin ()
    {
        return iterator(v);
    }
    iterator end ()
    {
        return iterator(0);
    }
};

int main ()
{
    vi xs {11, 51, 296, 487, (1<<9)-1};
    int v = 3;
    for (auto x : xs)
    {
        print("====");
        print(bitset<9>(x));
        for (auto y : IntSet(x)) print(y);
        print(bitset<9>(x & ((1<<9) - 1 - (1 << v))));
        print(bitset<9>(x | (1 << v)));
    }

    //print(bitset<10>(11));
    return 0;
}

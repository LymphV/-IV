#include <LymphV>

class BigInt
{
protected:
    using vc = vector<char>;
    const static int DIGIT = 10;

    vc data;

    BigInt & assign (int value)
    {
        for(data.clear(); value; value /= DIGIT)
            data.emplace_back(value % 10);
        return *this;
    }
    BigInt & assign (string value)
    {
        data.clear();
        if (value.size() == 1 && value[0] == '0') return *this;
        for (auto it = rbegin(value); it != rend(value); ++it)
            data.emplace_back(*it - '0');
        return *this;
    }
    public:
    string toString () const
    {
        string rst = "";
        for (auto it = rbegin(data); it != rend(data); ++it)
            rst += '0' + *it;
        return rst.empty() ? "0" : rst;//rst;//
    }

    BigInt & iadd (const BigInt & value, int offset = 0)
    {
        char carry = 0;
        int n = data.size(), m = value.data.size();
        if (!m) return *this;
        if (!n)
        {
            data.resize(offset);
            data.insert(end(data), begin(value.data), end(value.data));
            return *this;
        }

        if (n < offset) data.resize(offset), n = offset;
        for (int i = offset, j = 0; i < n || j < m || carry; ++i, ++j)
        {
            if (i < n)
            {

                data[i] = data[i] + (j < m ? value.data[j] : 0) + carry;
                carry = data[i] / DIGIT;
                data[i] %= DIGIT;
            }
            else
            {
                data.emplace_back((j < m ? value.data[j] : 0) + carry);
                carry = data[i] / DIGIT;
                data[i] %= DIGIT;
            }
        }
        return *this;
    }

    BigInt add (const BigInt & value, int offset = 0) const
    {
        BigInt rst(*this);
        return rst.iadd(value, offset);
    }

    BigInt mul (const BigInt & value) const
    {
        if (data.empty() || value.data.empty()) return 0;
        vector<BigInt> times{BigInt(), *this};
        BigInt rst;
        int offset = 0;
        for (auto it = begin(value.data); it != end(value.data); ++it, ++offset)
        {
            for (int i = times.size(); i <= *it; ++i)
                times.emplace_back(add(times[i - 1]));
            rst.iadd(times[*it], offset);
        }
        return rst;
    }
    BigInt & imul (const BigInt & value) {return *this = mul(value);}

public:
    BigInt (int value = 0) {assign(value);}
    BigInt (string value) {assign(value);}


    virtual ~BigInt() {}

    std::size_t size () const {return data.size();}

    operator string () const{return toString();}
    BigInt & operator+= (const BigInt & value){return iadd(value);}
    BigInt operator+ (const BigInt & value) const {return add(value);}
    BigInt & operator= (int value) {return assign(value);}
    BigInt & operator= (string value) {return assign(value);}
    BigInt & operator*= (const BigInt & value){return imul(value);}
    BigInt operator* (const BigInt & value) const {return mul(value);}
};


ostream & operator<< (ostream & out, const BigInt & value)
{
    return out << string(value);
}


int main ()
{
    vi xs{0, 10, 500, 1893};
    for (int x : xs) for (int y : xs)
    {
        print ("---");
        print (x, y, x * y);
        BigInt xx(x), yy(y);
        print (xx, yy, xx.mul(yy));
    }
    return 0;
}

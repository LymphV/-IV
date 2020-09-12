#include <LymphV>

struct A{double a;string b;};

int main ()
{
    ///pair 和struct拆包
    print(pii(1,2));
    auto [a, b] = pii(1,2);
    print (a, b);
    auto [c, d] = A{3.14, "pai"}; ///struct默认{}构造，class不能
    print (c, d);

    ///fail,结构化绑定不能嵌套
    /****
    auto [x, [y, z]] = pair<int,pii>{1,{2,3}};
    print (x, y, z);*/

    ///map拆包遍历
    map<int, string> i2s {{1, "h"}, {2, "hh"}, {3, "hhh"}};
    for (auto [k, v] : i2s)
        print (k, v);
    return 0;
}

#include <LymphV>

struct A{double a;string b;};

int main ()
{
    ///pair ��struct���
    print(pii(1,2));
    auto [a, b] = pii(1,2);
    print (a, b);
    auto [c, d] = A{3.14, "pai"}; ///structĬ��{}���죬class����
    print (c, d);

    ///fail,�ṹ���󶨲���Ƕ��
    /****
    auto [x, [y, z]] = pair<int,pii>{1,{2,3}};
    print (x, y, z);*/

    ///map�������
    map<int, string> i2s {{1, "h"}, {2, "hh"}, {3, "hhh"}};
    for (auto [k, v] : i2s)
        print (k, v);
    return 0;
}

#include <LymphV>


vi f()
{
    return {1,2,3,4};
}

void g1 (vi && v)
{
    print(v);
}
void g2(const vi & v)
{
    print(v);
}

void g3(vi & v)
{
    print(v);
}

class A
{
public:
    const vi & v;
    A(const vi & v):v(v){}

};

class B
{
public:
    vi && v;
    B(vi && v):v(move(v)){}

};


A testa ()
{
    vi v{1,2,3};
    A a(v);
    print(a.v);
    return a;
}

B testb ()
{
    vi v{1,2};
    B b(move(v));
    print(b.v);
    return b;
}


int main()
{
    g1(f());
    g2(f());
    ///g3(f()); r => l, wrong


    vi && v = f();
    ///g1(v); l => r, wrong
    g2(v);
    g3(v);

    g1(move(v));

    print(v);


    A && a = testa();
    ///print(a.v); invalid a.v because a.v has been deleted

    B && b = testb();
    ///print(b.v); still invalid b.v
    return 0;
}

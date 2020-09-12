#include <LymphV>

class A{}a;
class B : public A{}b;

class C{virtual void f(){}}c;
class D : public C{}d;

int main ()
{
    ///基本类型
    puts(typeid(1).name());
    debug (typeid (float).name());
    debug (typeid (double).name());
    debug (typeid (char).name());
    debug (typeid (bool).name());
    debug (typeid (string).name());
    debug (typeid (typeid(float)).name());

    print ();

    ///class
    debug (typeid (A).name());
    debug (typeid (B).name());
    debug (typeid (a).name());
    debug (typeid (b).name());

    A * p1 = &a;
    A * p2 = &b;
    B * p3 = &b;

    debug (typeid (p1).name());
    debug (typeid (p2).name());
    debug (typeid (p3).name());

    debug (typeid (*p1).name());
    debug (typeid (*p2).name());
    debug (typeid (*p3).name());

    print ();

    /*******************
    非虚类父指针指向子类，父指针内容类型是父类
    虚类父指针指向子类，父指针内容类型是子类
    */

    ///virtual class
    debug (typeid (C).name());
    debug (typeid (D).name());

    C * p4 = &c;
    C * p5 = &d;
    D * p6 = &d;

    debug (typeid (p4).name());
    debug (typeid (p5).name());
    debug (typeid (p6).name());

    debug (typeid (*p4).name());
    debug (typeid (*p5).name());
    debug (typeid (*p6).name());

    debug (typeid (p1).name());
    debug (typeid (p2).name());
    debug (typeid (p3).name());


    return 0;
}

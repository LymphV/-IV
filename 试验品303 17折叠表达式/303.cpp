#include <iostream>
using namespace std;

template<typename ... T>
auto sum(T ... arg)
{
    return (arg + ...);//сруш╣Ч
}

/*template <typename ... T>
void print (T ... args)
{
    cout << args << " " << ... << endl;
}*/


int main ()
{
    cout << sum(1, 2, 3) << endl;
    //print (1, 2, 3);
    return 0;
}

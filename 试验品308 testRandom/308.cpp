#include <LymphV>

int main ()
{
    default_random_engine e(time(0));
    FOR(i,10) print(e());

    uniform_int_distribution<unsigned int> ui(0,3);///±ÕÇø¼ä
    FOR(i,10) print(ui(e));

    uniform_real_distribution<double> ur(0.0, 1.0);
    FOR(i,10) print(ur(e));

    bernoulli_distribution b(0.3);
    FOR(i,10) print(b(e));


    return 0;
}

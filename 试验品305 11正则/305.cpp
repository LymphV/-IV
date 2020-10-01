#include<LymphV>

int main ()
{
    string str = "hhh233";
    regex r("[a-z0-9]+");

    debug(regex_match(str,regex(".**")));

    ///Õû¾äÆ¥Åä
    debug(regex_match(str,r));
    debug(regex_match(str,regex("\\d+")));
    debug(regex_match(str.begin()+7,str.end(),regex("\\d+")));

    ///Ìæ»»
    debug(regex_replace(str, regex("\\d+"), "hh"));
    debug(regex_replace(str, regex("\\d+?"), "+?"));

    ///×é
    auto wend = sregex_iterator();


    auto r1 = regex("(.)");
    for (auto i = sregex_iterator(str.begin(), str.end(), r1); i != wend; ++i)
        print (i->str());

    auto r2 = regex("(.)(.)");
    for (auto i = sregex_iterator(str.begin(), str.end(), r2); i != wend; ++i)
        print (i->str(1),i->str(2),i->str());

    auto r3 = regex("(.)(..)");
    for (auto i = sregex_iterator(str.begin(), str.end(), r3); i != wend; ++i)
        print (i->str(1),i->str(2),i->str());
    return 0;
}

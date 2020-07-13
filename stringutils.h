#ifndef STRINGUTILS_H
#define STRINGUTILS_H
#include <string>

using namespace std;

class StringUtils
{
public:
    StringUtils();

    static bool tarkistaPuhNro(string &puhNro);
    static bool pelkkiaNumeroita(string &str);
    static string tarkastaSoTu(string &soTu);

};

#endif // STRINGUTILS_H

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
    static string tarkastaTeksti(string &teksti);
    static string poistaValilyonnit(string &teksti);
    static string asetaKirjaimetIsoksi(string &teksti);

};

#endif // STRINGUTILS_H

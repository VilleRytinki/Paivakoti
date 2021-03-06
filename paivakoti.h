#ifndef PAIVAKOTI_H
#define PAIVAKOTI_H

#include <vector>
#include "perhe.h"

class Paivakoti
{
public:
    Paivakoti();
    Paivakoti(string nimi);
    Paivakoti(string nimi, string paivaKotiID);
    ~Paivakoti();

    void setNimi(string nimi);
    string getNimi();
    void setID(string paivaKotiID);
    string getPaivaKotiID();

    void tulostaPaivakoti();

    void lisaaPerhe(Perhe &perhe);

    void poistaPerhe(Perhe &perhe);

    void muokkaaPerheenTietoja(string nimi);
    void muokkaaPerheenTietoja(int perheID);
    void muokkaaja();

    vector<Perhe>::iterator etsiPerhe(string nimi);
    vector<Perhe>::iterator etsiPerhe(int perheID);

private:
    string nimi;
    string paivaKotiID;
    vector<Perhe> perheet;
};

#endif // PAIVAKOTI_H

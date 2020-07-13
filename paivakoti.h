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
    void etsiPerhe(string nimi);
    void etsiPerhe(int perheID);
    void poistaPerhe(string nimi);
    void poistaPerhe(int perheID);

private:
    string nimi;
    string paivaKotiID;
    vector<Perhe> perheet;
};

#endif // PAIVAKOTI_H

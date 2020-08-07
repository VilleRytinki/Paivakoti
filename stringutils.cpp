#include "stringutils.h"

StringUtils::StringUtils()
{

}

bool StringUtils::tarkistaPuhNro(string &puhNro) {
    bool tila = true;

    //Tarkastetaan, että puhelinnumerossa on oikea määrä elementtejä, sekä varmistetaan, että - merkin sijainti on 3.
    if(puhNro.size() > 3) {
        string alkuOsa = puhNro.substr(0,3);
        string loppuOsa = puhNro.substr(4,puhNro.size() -1);

        if (puhNro.size() < 11 || puhNro.size() > 11 || puhNro.find("-") != 3) {
            tila = false;

        }
        //Tarkastetaan, että numeron alku ja loppuosat sisältävät pelkkiä numeroita.
        if (!(pelkkiaNumeroita(alkuOsa)) || (!(pelkkiaNumeroita(loppuOsa)))) {
            tila = false;
        }
    } else {
        return false;
    }


     return tila;
}

bool StringUtils::pelkkiaNumeroita(string &str) {
    return str.find_first_not_of("0123456789") == std::string::npos;
}

string StringUtils::tarkastaTeksti(string &teksti) {
    string siivottu = "";
    string suurennettu;

    siivottu = poistaValilyonnit(teksti);

    suurennettu = asetaKirjaimetIsoksi(siivottu);


    return suurennettu;

}

string StringUtils::poistaValilyonnit(string &teksti) {
    string siivottu = "";
    int koko = teksti.length();

    for(int i = 0; i < koko; i++) {
        if(teksti[i] != ' ')
            siivottu.push_back(teksti[i]);
    }
    return siivottu;
}

string StringUtils::asetaKirjaimetIsoksi(string &teksti) {
    int koko = teksti.length();
    char kirjaimetIsona[koko];

    for(int i = 0; i < koko; i++) {
        kirjaimetIsona[i] = toupper(teksti[i]);

    }

    return kirjaimetIsona;
}

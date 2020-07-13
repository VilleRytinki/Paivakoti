#include "stringutils.h"

StringUtils::StringUtils()
{

}

bool StringUtils::tarkistaPuhNro(string &puhNro) {
    bool tila = true;
    string alkuOsa = puhNro.substr(0,3);
    string loppuOsa = puhNro.substr(4,puhNro.size() -1);


    //Tarkastetaan, että puhelinnumerossa on oikea määrä elementtejä, sekä varmistetaan, että - merkin sijainti on 3.
    if (puhNro.size() < 11 || puhNro.size() > 11 || puhNro.find("-") != 3) {
        tila = false;

    }

    //Tarkastetaan, että numeron alku ja loppuosat sisältävät pelkkiä numeroita.
    if (!(pelkkiaNumeroita(alkuOsa)) || (!(pelkkiaNumeroita(loppuOsa)))) {
        tila = false;
    }

     return tila;
}

bool StringUtils::pelkkiaNumeroita(string &str) {
    return str.find_first_not_of("0123456789") == std::string::npos;
}

string StringUtils::tarkastaSoTu(string &soTu) {
    int koko = soTu.length();
    char kirjaimet[koko];
    putchar(toupper(kirjaimet[0]));//ei jaksa enää.


    return kirjaimet;

}

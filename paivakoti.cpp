#include "paivakoti.h"
#include "perhe.h"
#include "tietokantautils.h"
#include "stringutils.h"

#include <iostream>
#include <exception>
#include <algorithm>


vector<Perhe>::iterator itrPerhe;

Paivakoti::Paivakoti()
{

}
Paivakoti::Paivakoti(string nimi) {
   setNimi(nimi);
}
Paivakoti::Paivakoti(string nimi, string paivaKotiID) {
   setNimi(nimi);
   setID(paivaKotiID);
}

Paivakoti::~Paivakoti() {
}

void Paivakoti::setNimi(string nimi) {
    this->nimi = nimi;
}

string Paivakoti::getNimi() {
    return this->nimi;
}

void Paivakoti::setID(string paivaKotiID) {
    this->paivaKotiID = paivaKotiID;
}

string Paivakoti::getPaivaKotiID() {
    return this->paivaKotiID;
}

void Paivakoti::tulostaPaivakoti() {
    if (perheet.empty()) {
        throw runtime_error("Tietokanta tyhja.");
    }

    for (itrPerhe = perheet.begin();itrPerhe != perheet.end();itrPerhe++) {
        cout << "Paivakoti: " << getNimi() << endl;
        cout << "Paivakoti ID: " << getPaivaKotiID() << endl;
        itrPerhe->tulostaPerhe();

    }

}

void Paivakoti::lisaaPerhe(Perhe &perhe) {
    perheet.push_back(perhe);
}

void Paivakoti::poistaPerhe(Perhe &perhe) {
    perheet.erase(std::remove(perheet.begin(),perheet.end(),perhe));

}

vector<Perhe>::iterator Paivakoti::etsiPerhe(string nimi) {

    itrPerhe = perheet.end();

    if(!perheet.empty()) {
        for(itrPerhe = begin(perheet); itrPerhe != perheet.end();) {
            if(itrPerhe->getPerheenNimi() == nimi) {
                return itrPerhe;
            } else {
                ++itrPerhe;
            }
        }
    } else {
        cout << "Perheita ei lisatty.\n";
    }

    return itrPerhe;
}


vector<Perhe>::iterator Paivakoti::etsiPerhe(int perheID) {

    itrPerhe = perheet.end();

    if(!perheet.empty()) {
        for (itrPerhe = begin(perheet);itrPerhe != perheet.end();) {
            if (itrPerhe->getPerheID() == perheID ){
                return itrPerhe;
            } else {
                ++itrPerhe;
            }
        }

    } else {
        cout << "Perheitä ei lisätty.\n";
    }
    return itrPerhe;
}


void Paivakoti::muokkaaPerheenTietoja(string nimi) {
    string toiminta;
    string soTu;

    nimi = soTu = StringUtils::tarkastaTeksti(nimi);

    itrPerhe = etsiPerhe(nimi);
    if(itrPerhe != perheet.end()) {
        itrPerhe->tulostaPerhe();
        muokkaaja();

    } else {
        cout << "oikeaa ei loytynyt.\n";
    }
}

void Paivakoti::muokkaaPerheenTietoja(int perheID) {
    string toiminta;
    string soTu;

    itrPerhe = etsiPerhe(perheID);
    if(itrPerhe != perheet.end()) {
        itrPerhe->tulostaPerhe();
        muokkaaja();

    } else {
        cout << "oikeaa ei loytynyt.\n";
    }
}

void Paivakoti::muokkaaja() {
    string toiminta;
    string soTu;

    while (true) {
        cout << "Haluatko lisata perheenjasenen tai muokata henkilotietoja? Voit myos poistaa perheen tiedot jarjestelmasta. |lisaa|muokkaa|poista|peruuta :";
        getline(cin,toiminta);
        toiminta = StringUtils::tarkastaTeksti(toiminta);

        if (toiminta == "PERUUTA") {
            break;
        } else if (toiminta == "LISAA") {
            TietokantaUtils::lisaaHenkilo(*itrPerhe);
        } else if (toiminta == "MUOKKAA") {
            cout << "Haluatko muokata vanhemman vai lapsen tietoja? |vanhempi|lapsi :";
            getline(cin,toiminta);
            toiminta = StringUtils::tarkastaTeksti(toiminta);

            if (toiminta == "VANHEMPI") {
                itrPerhe->tulostaVanhemmat();
                cout << "Syota sen vanhemman sosiaaliturvatunnus jonka tietoja haluat muuttaa :";
                getline(cin,soTu);
                itrPerhe->muokkaaVanhemmanTietoja(soTu);
            } else if (toiminta == "LAPSI") {
                itrPerhe->tulostaLapset();
                cout << "Syota sen lapsen sosiaaliturvatunnus jonka tietoja haluat muuttaa :";
                getline(cin,soTu);
                itrPerhe->muokkaaLapsenTietoja(soTu);

            }

        } else if (toiminta == "POISTA") {
            poistaPerhe(*itrPerhe);
            break;

        }
    }
}

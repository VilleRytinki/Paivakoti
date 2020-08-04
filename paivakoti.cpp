#include "paivakoti.h"
#include "perhe.h"
#include "tietokantautils.h"

#include <iostream>
#include <exception>


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
    cout << "Päiväkoti tuhottu" << endl;
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
        itrPerhe->tulostaPerhe();

    }

}

void Paivakoti::lisaaPerhe(Perhe &perhe) {
    perheet.push_back(perhe);
}

void Paivakoti::poistaPerhe(string nimi) {
    //Täällä tapahtuu jotain outoa terminate called after throwing an instance of 'std::bad_alloc'
    //what():  std::bad_alloc
    for (itrPerhe = perheet.begin();itrPerhe != perheet.end();itrPerhe++) {
        if (itrPerhe->getPerheenNimi() == nimi) {
            perheet.erase(itrPerhe);
        }
    }
}

void Paivakoti::poistaPerhe(int perheID) {
    for (itrPerhe = perheet.begin();itrPerhe != perheet.end();itrPerhe++) {
        if (itrPerhe->getPerheID() == perheID) {
            perheet.erase(itrPerhe);
        }
    }
}

void Paivakoti::etsiPerhe(string nimi) {
    string toiminta;
    int osumia= 0;
    for (itrPerhe = perheet.begin();itrPerhe != perheet.end(); itrPerhe++) {
        if (itrPerhe->getPerheenNimi() == nimi ){
            itrPerhe->tulostaPerhe();
            osumia++;

            while (true) {
                cout << "Haluatko lisata perheenjasenen tai muokata henkilotietoja tietoja? |lisaa|muokkaa|peruuta :";
                getline(cin,toiminta);

                if (toiminta == "peruuta") {
                    break;
                } else if (toiminta == "lisaa") {
                    TietokantaUtils::lisaaHenkilo(*itrPerhe);
                } else if (toiminta == "muokkaa") {
                    cout << "Haluatko muokata vanhemman vai lapsen tietoja? |vanhempi|lapsi :";
                    getline(cin,toiminta);
                    if (toiminta == "vanhempi") {
                        string soTu;
                        itrPerhe->tulostaVanhemmat();
                        cout << "Syota sen vanhemman sosiaaliturvatunnus jonka tietoja haluat muuttaa :";
                        getline(cin,soTu);
                        itrPerhe->muokkaaVanhemmanTietoja(soTu);
                    } //...tänne lapsen toiminta..

                }
            }

        }
    }

    if(osumia == 0) {
        cout << "Haetuilla tiedolla ei löytynyt perhetietoja." << endl;
    }
}

void Paivakoti::etsiPerhe(int perheID) {
    int osumia= 0;
    for (itrPerhe = perheet.begin();itrPerhe != perheet.end(); itrPerhe++) {
        if (itrPerhe->getPerheID() == perheID ){
            itrPerhe->tulostaPerhe();
            osumia++;
        }
    }

    if(osumia == 0) {
        cout << "Haetuilla tiedolla ei löytynyt perhetietoja." << endl;
    }
}

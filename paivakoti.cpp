#include "paivakoti.h"
#include "perhe.h"
#include "tietokantautils.h"

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

void Paivakoti::poistaPerhe(Perhe &perhe) {
    perheet.erase(std::remove(perheet.begin(),perheet.end(),perhe));

}
void Paivakoti::poistaPerhe(int perheID) {
    for (itrPerhe = perheet.begin();itrPerhe != perheet.end();itrPerhe++) {
        if (itrPerhe->getPerheID() == perheID) {
            perheet.erase(itrPerhe);
        }
    }
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

//Tämä ei ole vielä toimintakelpoinen
/*/void Paivakoti::etsiPerhe(int perheID) {
    int osumia= 0;
    itrPerhe = perheet.end();

    for (itrPerhe = perheet.begin();itrPerhe != perheet.end(); itrPerhe++) {
        if (itrPerhe->getPerheID() == perheID ){
            itrPerhe->tulostaPerhe();
            osumia++;

            muokkaaPerheenTietoja();
        }
    }

    if(osumia == 0) {
        cout << "Haetuilla tiedolla ei löytynyt perhetietoja." << endl;
    }
}
*/

void Paivakoti::muokkaaPerheenTietoja(string nimi) {
    string toiminta;
    string soTu;

    itrPerhe = etsiPerhe(nimi);
    if(itrPerhe != perheet.end()) {
        itrPerhe->tulostaPerhe();

        while (true) {
            cout << "Haluatko lisata perheenjasenen tai muokata henkilotietoja? Voit myös poistaa perheen tiedot jarjestelmasta. |lisaa|muokkaa|poista|peruuta :";
            getline(cin,toiminta);

            if (toiminta == "peruuta") {
                break;
            } else if (toiminta == "lisaa") {
                TietokantaUtils::lisaaHenkilo(*itrPerhe);
            } else if (toiminta == "muokkaa") {
                cout << "Haluatko muokata vanhemman vai lapsen tietoja? |vanhempi|lapsi :";
                getline(cin,toiminta);
                if (toiminta == "vanhempi") {
                    itrPerhe->tulostaVanhemmat();
                    cout << "Syota sen vanhemman sosiaaliturvatunnus jonka tietoja haluat muuttaa :";
                    getline(cin,soTu);
                    itrPerhe->muokkaaVanhemmanTietoja(soTu);
                } else if (toiminta == "lapsi") {
                    itrPerhe->tulostaLapset();
                    cout << "Syota sen lapsen sosiaaliturvatunnus jonka tietoja haluat muuttaa :";
                    getline(cin,soTu);
                    itrPerhe->muokkaaLapsenTietoja(soTu);

                }

            } else if (toiminta == "poista") {
                poistaPerhe(*itrPerhe);

            }
        }
    } else {
        cout << "oikeaa ei loytynyt.\n";
    }
}

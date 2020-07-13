#include "paivakoti.h"
#include "perhe.h"
#include <iostream>

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
    for (itrPerhe = perheet.begin();itrPerhe != perheet.end();itrPerhe++) {
        itrPerhe->tulostaPerhe();

    }

}

void Paivakoti::lisaaPerhe(Perhe &perhe) {
    perheet.push_back(perhe);
}

void Paivakoti::poistaPerhe(string nimi) {
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
    int osumia= 0;
    for (itrPerhe = perheet.begin();itrPerhe != perheet.end(); itrPerhe++) {
        if (itrPerhe->getPerheenNimi() == nimi ){
            itrPerhe->tulostaPerhe();
            osumia++;
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

#include "perhe.h"
#include "henkilo.h"
#include "tietokantautils.h"
#include "stringutils.h"
#include <iostream>
#include <math.h>
#include <algorithm>

vector<Vanhempi>::iterator itrVanhemmat;
vector<Lapsi>::iterator itrLapset;

Perhe::Perhe()
{

}
Perhe::Perhe(string perheenNimi) {
    setPerheenNimi(perheenNimi);
    setPerheenID(rand() % 100 + 1);
}

Perhe::~Perhe() {
    cout << "Perhe tuhottu" << endl;
}

void Perhe::setPerheenNimi(string &perheenNimi) {
    this->perheenNimi = StringUtils::tarkastaTeksti(perheenNimi);
}

string Perhe::getPerheenNimi() {
    return this->perheenNimi;
}

void Perhe::setPerheenID(int perheID) {
    this->perheID = perheID;
}

int Perhe::getPerheID() {
    return this->perheID;
}

vector<Vanhempi> Perhe::getListaVanhemmista() {
    return this->vanhemmat;
}

void Perhe::lisaaVanhempi(Vanhempi &vanhempi) {
    vanhemmat.push_back(vanhempi);
}

void Perhe::poistaVanhempi(Vanhempi &vanhempi) {

    vanhemmat.erase(std::remove(vanhemmat.begin(),vanhemmat.end(),vanhempi));


}

void Perhe::tulostaVanhemmat(){
    cout << "Perheen vanhemmat: " << endl;

    if (!vanhemmat.empty()) {
        for (itrVanhemmat = vanhemmat.begin();itrVanhemmat != vanhemmat.end(); itrVanhemmat++) {
            itrVanhemmat->tulostaHenkiloTiedot();
            cout << "\n";
        }
    } else {
        cout << "Vanhempia ei lisätty." << endl;
    }
}

vector<Vanhempi>::iterator Perhe::etsiVanhempi(string soTu) {


    itrVanhemmat = vanhemmat.end();

    if(!vanhemmat.empty()) {
        for (itrVanhemmat = begin(vanhemmat); itrVanhemmat != vanhemmat.end();) {
            if(itrVanhemmat->getSotu() == soTu) {
                return itrVanhemmat;
            } else {
                ++itrVanhemmat;
            }
        }
    } else {
        cout << "Vanhempia ei lisätty.\n";
    }
    return itrVanhemmat;
}

void Perhe::muokkaaVanhemmanTietoja(string soTu) {

    string toiminta;
    soTu = StringUtils::tarkastaTeksti(soTu);

    itrVanhemmat = etsiVanhempi(soTu);
    if(itrVanhemmat != vanhemmat.end()) {
        itrVanhemmat->tulostaHenkiloTiedot();
        while (true) {
            cout << "Haluatko poistaa henkilon vai muokata tietoja? |poista|muokkaa|peruuta| :" ;
            getline(cin,toiminta);
            toiminta = StringUtils::tarkastaTeksti(toiminta);

            if (toiminta == "PERUUTA") {
                break;
            } else if (toiminta == "POISTA") {
                poistaVanhempi(*itrVanhemmat);
                if(etsiVanhempi(soTu) == vanhemmat.end()) {
                    cout << "Vanhempi poistettu. \n";
                }

            } else if (toiminta == "MUOKKAA") {
                TietokantaUtils::kysyHenkiloTiedot(*itrVanhemmat);
            } else {
                cout << "Tarkasta syote.\n";
            }
        }
    } else {
        cout << "oikeaa ei löytynyt.\n";
    }
}

vector<Lapsi> Perhe::getListaLapsista() {
    return this->lapset;
}

void Perhe::lisaaLapsi(Lapsi &lapsi) {
    lapset.push_back(lapsi);
}

void Perhe::poistaLapsi(Lapsi &lapsi) {
    lapset.erase(remove(lapset.begin(),lapset.end(),lapsi));
}

vector<Lapsi>::iterator Perhe::etsiLapsi(string soTu) {
    itrLapset = lapset.end();

    if(!lapset.empty()) {
        for (itrLapset = begin(lapset); itrLapset != lapset.end(); itrLapset++) {
            if(itrLapset->getSotu() == soTu) {
                return itrLapset;
            }
        }
    } else {
        cout << "Lapsia ei lisätty.\n";
    }
    return itrLapset;
}

void Perhe::tulostaLapset(){
    cout << "Perheen lapset: " << endl;
    for (itrLapset = lapset.begin();itrLapset != lapset.end(); itrLapset++) {
            itrLapset->tulostaHenkiloTiedot();
            cout << "\n";
    }
}

void Perhe::muokkaaLapsenTietoja(string soTu) {

    string toiminta;
    soTu = StringUtils::tarkastaTeksti(soTu);

    itrLapset = etsiLapsi(soTu);
    if(itrLapset != lapset.end()) {
        itrLapset->tulostaHenkiloTiedot();

        while (true) {
            cout << "Haluatko poistaa henkilon vai muokata tietoja? |poista|muokkaa|peruuta| :" ;
            getline(cin,toiminta);
            toiminta = StringUtils::tarkastaTeksti(toiminta);

            if (toiminta == "PERUUTA") {
                break;
            } else if (toiminta == "POISTA") {
                poistaLapsi(*itrLapset);
                if(etsiLapsi(soTu) == lapset.end()) {
                    cout << "Lapsi poistettu. \n";
                }

            } else if (toiminta == "MUOKKAA") {
                TietokantaUtils::kysyHenkiloTiedot(*itrLapset);
            } else {
                cout << "Tarkasta syote.\n";
            }
        }
    } else {
        cout << "oikeaa ei löytynyt.\n";
    }
}

void Perhe::tulostaPerhe() {
    cout << "Perheen nimi: " << getPerheenNimi() << ". PerheID: " << getPerheID() << endl;
    tulostaVanhemmat();
    tulostaLapset();
}


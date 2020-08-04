#include "perhe.h"
#include "henkilo.h"
#include "tietokantautils.h"
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
    this->perheenNimi = perheenNimi;
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

/*lista<Vanhempi> Perhe::getListaVanhemmista() {
    return this->vanhemmat;
}*/

void Perhe::lisaaVanhempi(Vanhempi &vanhempi) {
    vanhemmat.push_back(vanhempi);
}

void Perhe::poistaVanhempi(Vanhempi &vanhempi) {

    /*itrVanhemmat = remove_if(vanhemmat.begin(), vanhemmat.end(), [&soTu](const Vanhempi &vanhempi) {
        return vanhempi.soTu == soTu;
    });*/

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
    int osumia= 0;
    itrVanhemmat = vanhemmat.end();

    if(!vanhemmat.empty()) {
        for (itrVanhemmat = begin(vanhemmat); itrVanhemmat != vanhemmat.end(); itrVanhemmat++) {
            if(itrVanhemmat->getSotu() == soTu) {
                osumia++;
                return itrVanhemmat;
            }
        }
    } else {
        cout << "Vanhempia ei lisätty.\n";
    }
    return itrVanhemmat;
}

void Perhe::muokkaaVanhemmanTietoja(string soTu) {

    string toiminta;

    itrVanhemmat = etsiVanhempi(soTu);
    if(itrVanhemmat != vanhemmat.end()) {
        itrVanhemmat->tulostaHenkiloTiedot();
    } else {
        cout << "oikeaa ei löytynyt.\n";
    }

    while (true) {
        cout << "Haluatko poistaa henkilon vai muokata tietoja? |poista|muokkaa|peruuta| :" ;
        getline(cin,toiminta);

        if (toiminta == "peruuta") {
            break;
        } else if (toiminta == "poista") {
            poistaVanhempi(*itrVanhemmat);

        } else if (toiminta == "muokkaa") {
            TietokantaUtils::kysyHenkiloTiedot(*itrVanhemmat);
        }
    }
}


void Perhe::etsiVanhemmanTiedot(string etunimi, string sukunimi) {
    int osumia= 0;

    for (itrVanhemmat = vanhemmat.begin();itrVanhemmat != vanhemmat.end(); itrVanhemmat++) {
        if (itrVanhemmat->getEtunimi() == etunimi && itrVanhemmat->getSukunimi() == sukunimi ){
            itrVanhemmat->tulostaHenkiloTiedot();
            osumia++;
        }

        if(osumia == 0) {
            cout << "Haetuilla tiedolla ei löytynyt henkilötietoja." << endl;
        }
    }
}

/*vector<Lapsi> Perhe::getListaLapsista() {
    return this->lapset;
}*/

void Perhe::lisaaLapsi(Lapsi &lapsi) {
    lapset.push_back(lapsi);
}

void Perhe::poistaLapsi(Lapsi &lapsi) {
    for (itrLapset = lapset.begin();itrLapset != lapset.end(); itrLapset++) {
        if (lapsi.getSotu() == itrLapset->getSotu()) {
            lapset.erase(itrLapset);
        }
    }
}

void Perhe::tulostaLapset(){
    cout << "Perheen lapset: " << endl;
    for (itrLapset = lapset.begin();itrLapset != lapset.end(); itrLapset++) {
            itrLapset->tulostaHenkiloTiedot();
            cout << "\n";
    }
}

void Perhe::etsiLapsenTiedot(string soTu) {
    int osumia= 0;

    for (itrLapset = lapset.begin();itrLapset != lapset.end(); itrLapset++) {
        if (itrLapset->getSotu() == soTu ){
            itrLapset->tulostaHenkiloTiedot();
            osumia++;
        }
    }

    if(osumia == 0) {
        cout << "Haetuilla tiedolla ei löytynyt henkilötietoja." << endl;
    }
}

void Perhe::etsiLapsenTiedot(string etunimi, string sukunimi) {
    int osumia= 0;

    for (itrLapset = lapset.begin();itrLapset != lapset.end(); itrLapset++) {
        if (itrLapset->getEtunimi() == etunimi && itrLapset->getSukunimi() == sukunimi ){
            itrLapset->tulostaHenkiloTiedot();
            osumia++;
        }

        if(osumia == 0) {
            cout << "Haetuilla tiedolla ei löytynyt henkilötietoja." << endl;
        }
    }
}

void Perhe::tulostaPerhe() {
    cout << "Perheen nimi: " << getPerheenNimi() << ". PerheID: " << getPerheID() << endl;
    tulostaVanhemmat();
    tulostaLapset();
}

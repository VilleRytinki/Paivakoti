#include "vanhempi.h"
#include "henkilo.h"
#include "stringutils.h"
#include <iostream>

Vanhempi::Vanhempi(): Henkilo()
{

}

Vanhempi::Vanhempi(string soTu, string etunimi, string sukunimi):Henkilo(etunimi,sukunimi) {
    setSotu(soTu);
}
Vanhempi::Vanhempi(string soTu, string etunimi, string sukunimi, string puhNro):Henkilo(etunimi, sukunimi) {
    setSotu(soTu);
    setPuhNro(puhNro);
}

Vanhempi::Vanhempi(string soTu, string etunimi, string sukunimi, string puhNro, Osoite &osoite):Henkilo(etunimi,sukunimi,osoite) {
    setSotu(soTu);
    setPuhNro(puhNro);
}

Vanhempi::~Vanhempi() {
    cout << "Vanhempi tuhottu." << endl;
}


void Vanhempi::setPuhNro(string &puhNro) {
    if (StringUtils::tarkistaPuhNro(puhNro)) {
        this->puhNro = puhNro;
    } else {
        cout << "Virhe puhelinnumeron syötteessä, tarkasta numero." << endl;
    }
}

string Vanhempi::getPuhNro(){return this->puhNro;}

void Vanhempi::tulostaHenkiloTiedot() {
    Henkilo::tulostaHenkiloTiedot();
    cout << "Sosiaaliturvatunnus :" << getSotu() << endl;
    cout << "Puhelinnumero: " << getPuhNro() << endl;

}

void Vanhempi::setSotu(string &soTu) {
    this->soTu = soTu;
}

string Vanhempi::getSotu() {return this->soTu;}

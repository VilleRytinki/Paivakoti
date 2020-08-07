#include "vanhempi.h"
#include "henkilo.h"
#include "stringutils.h"
#include <iostream>
#include <exception>

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
}


void Vanhempi::setPuhNro(string &puhNro) {
    if (StringUtils::tarkistaPuhNro(puhNro)) {
        this->puhNro = puhNro;
    } else {
        throw invalid_argument("tarkasta puhelinnumero");
    }
}

string Vanhempi::getPuhNro(){return this->puhNro;}

void Vanhempi::tulostaHenkiloTiedot() {
    Henkilo::tulostaHenkiloTiedot();
    cout << "Sosiaaliturvatunnus :" << getSotu() << endl;
    cout << "Puhelinnumero: " << getPuhNro() << endl;

}

void Vanhempi::setSotu(string &soTu) {
    soTu = StringUtils::tarkastaTeksti(soTu);
    this->soTu = soTu;
}

string Vanhempi::getSotu() {return this->soTu;}

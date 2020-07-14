#include "vanhempi.h"
#include "henkilo.h"
#include "stringutils.h"
#include <iostream>

Vanhempi::Vanhempi(): Henkilo()
{

}

Vanhempi::Vanhempi(string soTu, string etunimi, string sukunimi):Henkilo(soTu,etunimi,sukunimi) {

}
Vanhempi::Vanhempi(string soTu, string etunimi, string sukunimi, string puhNro):Henkilo(soTu, etunimi, sukunimi) {
    setPuhNro(puhNro);
}

Vanhempi::Vanhempi(string soTu, string etunimi, string sukunimi, string puhNro, Osoite &osoite):Henkilo(soTu,etunimi,sukunimi,osoite) {
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
    cout << "Puhelinnumero: " << getPuhNro() << endl;

}

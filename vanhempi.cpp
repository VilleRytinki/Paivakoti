#include "vanhempi.h"
#include "henkilo.h"
#include <iostream>

Vanhempi::Vanhempi(): Henkilo()
{

}

Vanhempi::Vanhempi(string soTu, string etunimi, string sukunimi):Henkilo(soTu,etunimi,sukunimi) {

}
Vanhempi::Vanhempi(string soTu, string etunimi, string sukunimi, string puhNro):Henkilo(soTu, etunimi, sukunimi, puhNro) {

}

Vanhempi::Vanhempi(string soTu, string etunimi, string sukunimi, string puhNro, Osoite &osoite):Henkilo(soTu,etunimi,sukunimi,puhNro,osoite) {

}

Vanhempi::~Vanhempi() {
    cout << "Vanhempi tuhottu." << endl;
}


void Vanhempi::tulostaHenkiloTiedot() {
    Henkilo::tulostaHenkiloTiedot();
    cout << "Vanhemman metodia kutsuttu." << endl;

}

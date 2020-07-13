#include "lapsi.h"
#include <iostream>

Lapsi::Lapsi()
{

}

Lapsi::Lapsi(string soTu, string etunimi, string sukunimi,string ryhma):Henkilo(soTu, etunimi, sukunimi) {
    setRyhma(ryhma);
}

Lapsi::~Lapsi(){
    cout << "Lapsi tuhottu." << endl;
}

void Lapsi::setRyhma(string &ryhma) {
    this->ryhma = ryhma;
}
string Lapsi::getRyhma() {
    return this->ryhma;
}

void Lapsi::tulostaHenkiloTiedot(){
    Henkilo::tulostaHenkiloTiedot();
    cout << "Ryhmä: " << getRyhma() << endl;

}

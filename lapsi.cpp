#include "lapsi.h"
#include <iostream>
#include "stringutils.h"

Lapsi::Lapsi()
{

}

Lapsi::Lapsi(string soTu, string etunimi, string sukunimi,string ryhma):Henkilo(etunimi, sukunimi) {
    setSotu(soTu);
    setRyhma(ryhma);
}

Lapsi::~Lapsi(){
    cout << "Lapsi tuhottu." << endl;
}

void Lapsi::setRyhma(string &ryhma) {
    this->ryhma = StringUtils::tarkastaTeksti(ryhma);
}
string Lapsi::getRyhma() {
    return this->ryhma;
}

void Lapsi::tulostaHenkiloTiedot(){
    Henkilo::tulostaHenkiloTiedot();
    cout << "Sosiaaliturvatunnus :" << getSotu() << endl;
    cout << "Ryhmä: " << getRyhma() << endl;

}

void Lapsi::setSotu(string &soTu) {
    this->soTu = StringUtils::tarkastaTeksti(soTu);
}

string Lapsi::getSotu() {return this->soTu;}

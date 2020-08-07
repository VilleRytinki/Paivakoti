#include "henkilo.h"
#include <iostream>
#include "osoite.h"
#include "stringutils.h"

Henkilo::Henkilo()
{


}

Henkilo::Henkilo(string etunimi, string sukunimi) {
    setEtunimi(etunimi);
    setSukunimi(sukunimi);
    setOsoite(osoite);

}


Henkilo::Henkilo(string etunimi, string sukunimi, Osoite &osoite) {
    setEtunimi(etunimi);
    setSukunimi(sukunimi);
    setOsoite(osoite);

}

Henkilo::~Henkilo() {
}


void Henkilo::setEtunimi(string &etunimi){
    this->etunimi = StringUtils::tarkastaTeksti(etunimi);
}

string Henkilo::getEtunimi(){return this->etunimi;}

void Henkilo::setSukunimi(string &sukunimi) {
    this->sukunimi = StringUtils::tarkastaTeksti(sukunimi);
}

string Henkilo::getSukunimi() {return this->sukunimi;}

void Henkilo::setOsoite(Osoite &osoite){
    this->osoite = osoite;
}

Osoite Henkilo::getOsoite(){return this->osoite;}



void Henkilo::kysyOsoiteTiedot() {

}


void Henkilo::tulostaHenkiloTiedot(){
    cout << "Etunimi: " << getEtunimi() << endl;
    cout << "Sukunimi: " << getSukunimi() << endl;
    osoite.tulostaOsoite();

}






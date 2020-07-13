#include "henkilo.h"
#include <iostream>
#include "stringutils.h"
#include "osoite.h"

Henkilo::Henkilo()
{


}

Henkilo::Henkilo(string soTu, string etunimi, string sukunimi) {
    Osoite osoite = *new Osoite();
    setSotu(soTu);
    setEtunimi(etunimi);
    setSukunimi(sukunimi);
    setOsoite(osoite);
    this->puhNro = "-";
}

Henkilo::Henkilo(string soTu, string etunimi, string sukunimi, string puhNro) {
    setSotu(soTu);
    setEtunimi(etunimi);
    setSukunimi(sukunimi);
    setPuhNro(puhNro);
    this->puhNro = "-";
}

Henkilo::Henkilo(string soTu, string etunimi, string sukunimi,  string puhNro, Osoite &osoite) {
    setSotu(soTu);
    setEtunimi(etunimi);
    setSukunimi(sukunimi);
    setOsoite(osoite);
    setPuhNro(puhNro);
}

Henkilo::~Henkilo() {
    cout << "Henkilö tuhottu." << endl;
}

void Henkilo::setSotu(string &soTu) {
    this->soTu = soTu;
}

string Henkilo::getSotu() {return this->soTu;}

void Henkilo::setEtunimi(string &etunimi){
    this->etunimi = etunimi;
}

string Henkilo::getEtunimi(){return this->etunimi;}

void Henkilo::setSukunimi(string &sukunimi) {
    this->sukunimi = sukunimi;
}

string Henkilo::getSukunimi() {return this->sukunimi;}

void Henkilo::setOsoite(Osoite &osoite){
    this->osoite = osoite;
}

Osoite Henkilo::getOsoite(){return this->osoite;}

void Henkilo::setPuhNro(string &puhNro) {
    if (StringUtils::tarkistaPuhNro(puhNro)) {
        this->puhNro = puhNro;
    } else {
        cout << "Virhe puhelinnumeron syötteessä, tarkasta numero." << endl;
    }
}

void Henkilo::kysyOsoiteTiedot() {

}


string Henkilo::getPuhNro(){return this->puhNro;}

void Henkilo::tulostaHenkiloTiedot(){
    cout << "Etunimi: " << getEtunimi() << endl;
    cout << "Sukunimi: " << getSukunimi() << endl;
    cout << "Sosiaaliturvatunnus: " << getSotu() << endl;
    osoite.tulostaOsoite();
    cout << "Puhelinnumero: " << getPuhNro() << endl;
}






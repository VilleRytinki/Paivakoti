#include "osoite.h"
#include <iostream>
#include "stringutils.h"


Osoite::Osoite()
{

}

Osoite::Osoite(string katuOsoite, string postiNro, string paikkaKunta) {
    setKatuOsoite(katuOsoite);
    setPostiNro(postiNro);
    setPaikkaKunta(paikkaKunta);
}

Osoite::~Osoite(){
}

void Osoite::setKatuOsoite(string katuOsoite) {
    this->katuOsoite = StringUtils::asetaKirjaimetIsoksi(katuOsoite);
}

string Osoite::getKatuOsoite() {
    return this->katuOsoite;
}

void Osoite::setPostiNro(string postiNro) {
    if(StringUtils::pelkkiaNumeroita(postiNro)) {
        this->postiNro = postiNro;
    } else {
        throw invalid_argument("Postinumerossa muita kuin numeroita. Tarkasta numero.\n");
    }
}
string Osoite::getPostiNro() {
    return this->postiNro;
}

void Osoite::setPaikkaKunta(string paikkaKunta) {
    this->paikkaKunta = StringUtils::tarkastaTeksti(paikkaKunta);
}

string Osoite::getPaikkaKunta() {
    return this->paikkaKunta;
}

void Osoite::tulostaOsoite(){
    cout << "Osoite: " << getKatuOsoite() << ", " << getPostiNro() << ", " << getPaikkaKunta() << "." << endl;
}

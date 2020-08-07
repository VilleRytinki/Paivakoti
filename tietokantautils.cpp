#include "tietokantautils.h"
#include "vanhempi.h"
#include "lapsi.h"
#include "perhe.h"
#include "osoite.h"
#include "paivakoti.h"

#include <iostream>
#include <vector>

string komento;
string etunimi;
string sukunimi;
string soTu;
string puhNro;
string ryhma;

string katuOsoite;
string postiNro;
string paikkaKunta;

Osoite osoite;



TietokantaUtils::TietokantaUtils()
{

}
void TietokantaUtils::lisaaHenkilo(Perhe& perhe) {
    while (true) {

        cout << "\nHaluatko lisata vanhemman vai lapsen?|vanhempi|lapsi|peruuta|:";
        getline(cin,komento);

        int vanhempi = komento.compare("vanhempi");
        int lapsi = komento.compare("lapsi");
        int lopeta = komento.compare("peruuta");

        if(lopeta == 0) {
            break;
        } else if (vanhempi == 0) {
            Vanhempi vanhempi = *new Vanhempi();
            TietokantaUtils::kysyHenkiloTiedot(vanhempi);
            TietokantaUtils::kysyOsoiteTiedot(vanhempi);

            perhe.lisaaVanhempi(vanhempi);


        } else if(lapsi == 0) {

            while (true) {
                try {
                    Lapsi lapsi = *new Lapsi();
                    TietokantaUtils::kysyHenkiloTiedot(lapsi);
                    TietokantaUtils::kysyOsoiteTiedot(lapsi);
                    perhe.lisaaLapsi(lapsi);
                } catch (runtime_error e) {
                    cout << e.what();
                    continue;
                }
                break;
            }

        } else {
            cout << "komentoa ei tunnistettu" << endl;
            continue;
        }

    }
}


void TietokantaUtils::kysyHenkiloTiedot(Vanhempi &henkilo) {

    cout << "sosiaaliturvatunnus: ";
    getline(cin,soTu);
    cout << "etunimi: ";
    getline(cin,etunimi);
    cout << "sukunimi: ";
    getline(cin,sukunimi);

    henkilo.setSotu(soTu);
    henkilo.setEtunimi(etunimi);
    henkilo.setSukunimi(sukunimi);

    while (true) {
        try {
            cout << "puhelinnumero|muodossa xxx-xxxxxxx|: ";
            getline(cin,puhNro);
            henkilo.setPuhNro(puhNro);
        } catch (invalid_argument e) {
            cout << e.what() << "\n";
            continue;
        }
        break;
   }
}

void TietokantaUtils::kysyHenkiloTiedot(Lapsi &lapsi) {

    cout << "sosiaaliturvatunnus: ";
    getline(cin,soTu);
    cout << "etunimi: ";
    getline(cin,etunimi);
    cout << "sukunimi: ";
    getline(cin,sukunimi);
    cout << "Ryhman nimi: ";
    getline(cin,ryhma);

    lapsi.setSotu(soTu);
    lapsi.setEtunimi(etunimi);
    lapsi.setSukunimi(sukunimi);
    lapsi.setRyhma(ryhma);

}

void TietokantaUtils::kysyOsoiteTiedot(Henkilo &vanhempi) {

    osoite =*new Osoite();

    cout << "\nAnna osoitetiedot:" << endl;
    cout << "Katuosoite: ";
    getline(cin,katuOsoite);
    while (true) {
        try {
            cout << "Postinumero: ";
            getline(cin,postiNro);
            osoite.setPostiNro(postiNro);
        } catch (invalid_argument e) {
            cout << e.what();
            continue;
        }
        break;
    }
    cout << "Paikkakunta: ";
    getline(cin,paikkaKunta);

    osoite.setKatuOsoite(katuOsoite);
    osoite.setPaikkaKunta(paikkaKunta);

    vanhempi.setOsoite(osoite);


}

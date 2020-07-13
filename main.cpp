#include <iostream>
#include <list>
#include <iterator>
#include <string>

#include "string.h"
#include "lapsi.h"
#include "osoite.h"
#include "vanhempi.h"
#include "perhe.h"
#include "paivakoti.h"

using namespace std;
Osoite osoite;
Paivakoti* paivakoti;
Perhe perhe;

string paivaKodinNimi;
string paivaKodinID;

string perheenNimi;
int perheID;

string toiminta;
string etunimi;
string sukunimi;
string soTu;
string puhNro;
string ryhma;

string katuOsoite;
string postiNro;
string paikkaKunta;


void lisaaHenkilo();
void kysyOsoiteTiedot(Henkilo &henkilo);
void kysyHenkiloTiedot(Henkilo &henkilo);

int main()
{
    cout << "Tervetuloa päivähoidon asiakastietojärjestelmään.\n";
    cout << "Anna päiväkodin nimi: ";
    getline(cin,paivaKodinNimi);

    cout << "Anna päiväkodin ID: ";
    getline(cin,paivaKodinID);


    paivakoti = new Paivakoti(paivaKodinNimi,paivaKodinID);

    while (true) {


        cout << "Haluatko lisätä perheen, etsiä tietokannasta vai poistaa tietoja? Voit myös tulostaa päväkodin asiakkaiden tiedot. \n|lisää|etsi|poista|lopeta|tulosta|: ";
        getline(cin,toiminta);

        if(toiminta == "lopeta") {
            break;
        } else if (toiminta == "lisaa") {
            cout << "Anna perheen nimi(esim. Virtanen):" ;
            getline(cin,perheenNimi);

            perhe = *new Perhe(perheenNimi);

            lisaaHenkilo();

            paivakoti->lisaaPerhe(perhe);

        } else if (toiminta == "etsi") {
            cout << "Etsitäänkö nimellä vai ID numerolla? |nimi|ID|:";
            getline(cin,toiminta);

            if(toiminta == "nimi") {
                cout << "Anna perheen nimi(esim. Virtanen):" ;
                getline(cin,perheenNimi);

                paivakoti->etsiPerhe(perheenNimi);

            } else if (toiminta == "ID") {
                cout << "Syötä perheen ID(esim. 1):";
                cin >> perheID;

                paivakoti->etsiPerhe(perheID);

            }
        } else if (toiminta == "poista") {
            cout << "Etsitäänkö nimellä vai ID numerolla? |nimi|ID|:";
            getline(cin,toiminta);

            if(toiminta == "nimi") {
                cout << "Anna perheen nimi(esim. Virtanen):" ;
                getline(cin,perheenNimi);

                paivakoti->poistaPerhe(perheenNimi);

            } else if (toiminta == "ID") {
                cout << "Syötä perheen ID(esim. 1):";
                cin >> perheID;

                paivakoti->poistaPerhe(perheID);

            }
        } else if (toiminta == "tulosta") {
            paivakoti->tulostaPaivakoti();

        } else {
            cout << "Komentoa ei tunnistettu";
            continue;
        }
    }

   delete paivakoti;

    return 0;
}

void kysyOsoiteTiedot(Henkilo &henkilo) {


    cout << "\nAnna osoitetiedot:" << endl;
    cout << "Katuosoite: ";
    //cin.ignore();
    getline(cin,katuOsoite);
    cout << "Postinumero: ";
    getline(cin,postiNro);
    cout << "Paikkakunta: ";
    getline(cin,paikkaKunta);

    osoite =*new Osoite(katuOsoite,postiNro,paikkaKunta);

    henkilo.setOsoite(osoite);


}

void kysyHenkiloTiedot(Henkilo &henkilo) {

    cout << "sosiaaliturvatunnus: ";
    getline(cin,soTu);
    cout << "etunimi: ";
    getline(cin,etunimi);
    cout << "sukunimi: ";
    getline(cin,sukunimi);
    cout << "puhelinnumero|muodossa xxx-xxxxxxx|: ";
    getline(cin,puhNro);

    henkilo.setSotu(soTu);
    henkilo.setEtunimi(etunimi);
    henkilo.setSukunimi(sukunimi);
    henkilo.setPuhNro(puhNro);
}

void lisaaHenkilo() {
    while (true) {

        cout << "\nHaluatko lisätä vanhemman vai lapsen?|vanhempi|lapsi|lopeta|:";
        getline(cin,toiminta);

        int vanhempi = toiminta.compare("vanhempi");
        int lapsi = toiminta.compare("lapsi");
        int lopeta = toiminta.compare("lopeta");

        if(lopeta == 0) {
            break;
        } else if (vanhempi == 0) {
            Vanhempi vanhempi = *new Vanhempi();
            kysyHenkiloTiedot(vanhempi);
            kysyOsoiteTiedot(vanhempi);

            perhe.lisaaVanhempi(vanhempi);


        } else if(lapsi == 0) {
            Lapsi lapsi = *new Lapsi();
            kysyHenkiloTiedot(lapsi);
            kysyOsoiteTiedot(lapsi);

            perhe.lisaaLapsi(lapsi);


        } else {
            cout << "komentoa ei tunnistettu" << endl;
            continue;
        }

    }
}

void etsiPerhe(string nimi) {
    cout << "Anna perheen nimi(esim. Virtanen):" ;
    getline(cin,perheenNimi);
}

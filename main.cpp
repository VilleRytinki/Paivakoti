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
#include "tietokantautils.h"
#include "stringutils.h"

using namespace std;

Paivakoti* paivakoti;


string paivaKodinNimi;
string paivaKodinID;

string perheenNimi;
int perheID;

string toiminta;





int main()
{
    cout << "Tervetuloa paivahoidon asiakastietojarjestelmaan.\n";
    cout << "Anna paivakodin nimi: ";
    getline(cin,paivaKodinNimi);

    cout << "Anna paivakodin ID: ";
    getline(cin,paivaKodinID);


    paivakoti = new Paivakoti(paivaKodinNimi,paivaKodinID);

    while (true) {


        cout << "Haluatko lisata perheen, etsia tietokannasta ja muokata tietoja? Voit myos tulostaa paivakodin asiakkaiden tiedot. \n|lisaa|etsi|lopeta|tulosta|: ";
        getline(cin,toiminta);
        toiminta = StringUtils::tarkastaTeksti(toiminta);

        if(toiminta == "LOPETA") {
            break;
        } else if (toiminta == "LISAA") {
            cout << "Anna perheen nimi(esim. Virtanen):" ;
            getline(cin,perheenNimi);

            Perhe perhe = *new Perhe(perheenNimi);

            TietokantaUtils::lisaaHenkilo(perhe);

            paivakoti->lisaaPerhe(perhe);

        } else if (toiminta == "ETSI") {
            cout << "Etsitaankö nimella vai ID numerolla? |nimi|ID|:";
            getline(cin,toiminta);
            toiminta = StringUtils::tarkastaTeksti(toiminta);

            if(toiminta == "NIMI") {
                cout << "Anna perheen nimi(esim. Virtanen):" ;
                getline(cin,perheenNimi);

                paivakoti->muokkaaPerheenTietoja(perheenNimi);

            } else if (toiminta == "ID") {
                cout << "Syota perheen ID(esim. 1):";
                cin >> perheID;

                paivakoti->muokkaaPerheenTietoja(perheID);

            }
        } else if (toiminta == "TULOSTA") {
            try {
                paivakoti->tulostaPaivakoti();
            } catch (runtime_error e) {
                cout << e.what() << "\n";
            }

        } else {
            cout << "Komentoa ei tunnistettu";
            continue;
        }
    }

    delete paivakoti;

    return 0;
}





#ifndef PERHE_H
#define PERHE_H
#include "vanhempi.h"
#include "lapsi.h"
#include <vector>


class Perhe
{
public:
    Perhe();
    Perhe(string perheenNimi);
    ~Perhe();

    void setPerheenNimi(string &perheenNimi);
    string getPerheenNimi();
    void setPerheenID(int perheID);
    int getPerheID();
    void lisaaVanhempi(Vanhempi &vanhempi);
    void poistaVanhempi(Vanhempi &vanhempi);
    vector<Vanhempi>::iterator etsiVanhempi(string soTu);

    //lista<Vanhempi> getListaVanhemmista();


    void lisaaLapsi(Lapsi &lapsi);
    void poistaLapsi(Lapsi &lapsi);

    //vector<Lapsi> getListaLapsista();

    void etsiLapsenTiedot(string sotU);
    void etsiLapsenTiedot(string etunimi, string sukunimi);
    void muokkaaVanhemmanTietoja(string soTu);
    void etsiVanhemmanTiedot(string etunimi,string sukunimi);

    void tulostaPerhe();
    void tulostaVanhemmat();
    void tulostaLapset();

private:
    vector<Vanhempi> vanhemmat;
    vector<Lapsi> lapset;

    string perheenNimi;
    int perheID;
};

#endif // PERHE_H

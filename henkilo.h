#ifndef HENKILO_H
#define HENKILO_H

#include <string>
#include "osoite.h"

using namespace std;

class Henkilo
{
public:
    Henkilo();
    Henkilo(string soTu, string etunimi, string sukunimi);
    Henkilo(string soTu, string etunimi, string sukunimi, string puhNro);
    Henkilo(string soTu, string etunimi, string sukunimi, string puhNro, Osoite &osoite);
    virtual ~Henkilo();

    void setSotu(string &soTu);
    string getSotu();
    void setEtunimi(string &etunimi);
    string getEtunimi();
    void setSukunimi(string &sukunimi);
    string getSukunimi();
    void setOsoite(Osoite &osoite);
    Osoite getOsoite();
    void setPuhNro(string &puhNro);
    string getPuhNro();

    void kysyOsoiteTiedot();

    virtual void tulostaHenkiloTiedot();

private:
    string soTu;
    string etunimi;
    string sukunimi;
    Osoite osoite;
    string puhNro;

};

#endif // HENKILO_H

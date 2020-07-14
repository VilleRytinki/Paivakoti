#ifndef VANHEMPI_H
#define VANHEMPI_H
#include "henkilo.h"


class Vanhempi:public Henkilo
{
public:
    Vanhempi();
    Vanhempi(string soTu, string etunimi, string sukunimi);
    Vanhempi(string soTu, string etunimi, string sukunimi, string puhNro);
    Vanhempi(string soTu, string etunimi, string sukunimi, string puhNro, Osoite &osoite);
    ~Vanhempi();

    void setPuhNro(string &puhNro);
    string getPuhNro();

    void tulostaHenkiloTiedot() override;

private:
    string puhNro;
};

#endif // VANHEMPI_H

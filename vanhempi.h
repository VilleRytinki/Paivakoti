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


    void tulostaHenkiloTiedot() override;

private:

};

#endif // VANHEMPI_H

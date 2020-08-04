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
    void setSotu(string &soTu);
    string getSotu();

    void tulostaHenkiloTiedot() override;

    inline bool operator == (const Vanhempi &vanhempi) {
        return vanhempi.soTu == soTu;
    }

    inline bool operator != (const Vanhempi &vanhempi) {
        return vanhempi.soTu != soTu;
    }

    string soTu;

private:
    string puhNro;

};

#endif // VANHEMPI_H

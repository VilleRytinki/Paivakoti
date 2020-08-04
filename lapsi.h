#ifndef LAPSI_H
#define LAPSI_H

#include "henkilo.h"


class Lapsi:public Henkilo
{
public:
    Lapsi();
    Lapsi(string soTu, string etunimi, string sukunimi, string ryhma);

    ~Lapsi();

    void setRyhma(string &ryhma);
    string getRyhma();

    void setSotu(string &soTu);
    string getSotu();

    void tulostaHenkiloTiedot() override;

    string soTu;
private:
    string ryhma;
};

#endif // LAPSI_H

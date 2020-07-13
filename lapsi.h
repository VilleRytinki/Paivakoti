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

    void tulostaHenkiloTiedot() override;
private:
    string ryhma;
};

#endif // LAPSI_H

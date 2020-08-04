#ifndef TIETOKANTAUTILS_H
#define TIETOKANTAUTILS_H

#include "vanhempi.h"
#include "lapsi.h"
#include "perhe.h"


class TietokantaUtils
{
public:
    TietokantaUtils();

    static void lisaaHenkilo(Perhe& perhe);
    static void kysyHenkiloTiedot(Vanhempi &henkilo);
    static void kysyHenkiloTiedot(Lapsi &lapsi);
    static void kysyOsoiteTiedot(Henkilo &vanhempi);

};

#endif // TIETOKANTAUTILS_H

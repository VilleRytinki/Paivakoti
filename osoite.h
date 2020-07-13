#ifndef OSOITE_H
#define OSOITE_H

#include <string>


using namespace std;

class Osoite
{
public:
    Osoite();
    Osoite(string katuOsoite, string postiNro, string paikkaKunta);
    virtual ~Osoite();

    void setKatuOsoite(string katuOsoite);
    string getKatuOsoite();
    void setPostiNro(string postiNro);
    string getPostiNro();
    void setPaikkaKunta(string paikkaKunta);
    string getPaikkaKunta();

    void tulostaOsoite();



private:
    string katuOsoite;
    string postiNro;
    string paikkaKunta;
};

#endif // OSOITE_H

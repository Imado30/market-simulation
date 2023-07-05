#include <../include/Angebot.hpp>
#include <iostream>
#include <string>
#include <map>

namespace Handelsplatz
{

    Angebot::Angebot(const std::string &warentyp, int anzahl, double preis)
        : warentyp(warentyp), anzahl(anzahl), preis(preis) {}

    std::string Angebot::get_warentyp() const
    {
        return warentyp;
    }

    int Angebot::get_anzahl() const
    {
        return anzahl;
    }

    double Angebot::get_preis() const
    {
        return preis;
    }
}
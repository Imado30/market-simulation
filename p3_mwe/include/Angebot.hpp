#pragma once
#include <iostream>
#include <vector>
#include <map>

namespace Handelsplatz{

    class Angebot {

    public:
        Angebot(const std::string& warentyp, int anzahl, double preis);

        std::string get_warentyp() const;
        int get_anzahl() const;
        double get_preis() const;

    private:
        std::string warentyp;
        int anzahl;
        double preis;
};
}
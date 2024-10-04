#pragma once
#include <iostream>
#include <vector>
#include <map>

namespace Handelsplatz
{
    class Angebot
    {
    public:
        /**
         * @brief Construct a new Angebot object
         *
         * @param warentyp
         * @param anzahl
         * @param preis
         */
        Angebot(const std::string &warentyp, int anzahl, double preis);

        /**
         * @brief Get the warentyp object
         *
         * @return std::string
         */
        std::string get_warentyp() const;

        /**
         * @brief Get the anzahl object
         *
         * @return int
         */
        int get_anzahl() const;

        /**
         * @brief Get the preis object
         *
         * @return double
         */
        double get_preis() const;

    private:
        /**
         * @brief Speichert den Warentyp
         *
         */
        std::string warentyp;

        /**
         * @brief Speichert die Anzahl der Ware
         *
         */
        int anzahl;

        /**
         * @brief Speichert den Preis der Ware
         *
         */
        double preis;
    };
}
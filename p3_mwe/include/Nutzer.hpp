#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "../include/Angebot.hpp"

namespace Handelsplatz
{

    class Nutzer
    {
    public:
        /**
         * @brief Construct a new Nutzer object
         *
         * @param benutzername
         * @param passwort
         */
        Nutzer(std::string benutzername, std::string passwort);

        /**
         * @brief Set the berry object
         *
         * @param betrag
         */
        void set_berry(double betrag);

        /**
         * @brief Es wird der angegebene Betrag mit der Menge mulitpliziert und vom Kontostand subtrahiert
         *
         * @param betrag
         * @param menge
         */
        void sub_balance(double betrag, int menge);

        /**
         * @brief Es wird der angegebene Betrag mit der Menge mulitpliziert und auf den Kontostand addiert
         *
         * @param betrag
         * @param menge
         */
        void add_balance(double betrag, int menge);

        /**
         * @brief Es wird die Ware im Inventar gesucht
         *
         * @param ware
         * @return true
         * @return false
         */
        bool find_ware(std::string ware);

        /**
         * @brief Es wird das Angebot in my_offer gesucht
         *
         * @param id
         * @return true
         * @return false
         */
        bool find_my_offer(int id);

        /**
         * @brief Fügt ein Angebot in my_offer ein
         *
         */
        void offer_einfügen(std::pair<int, Angebot> paar);

        /**
         * @brief Es wird eine Ware mit der jeweiligen Anzahl in das Inventar hinzugefügt
         *
         * @param handelsgut
         * @param anzahl
         */
        void add(const std::string &handelsgut, int anzahl);

        /**
         * @brief Hat dieselbe Funktion wie add nur das man als Parameter ein Tupel hat
         *
         * @param paar
         */
        void add_tuple(std::pair<std::string, int> paar);

        /**
         * @brief Es wird die ID in my_offer gefunden und das paar mit (Ware, Anzahl) zurückgegeben
         *
         * @param ID
         * @return std::pair<std::string,int>
         */
        std::pair<std::string, int> add_for_delete(int ID);

        /**
         * @brief Es wird ein Handelsgut vom Inventar gelöscht oder die Anzahl wird reduziert
         *
         * @param handelsgut
         * @param anzahl
         */
        void remove(const std::string &handelsgut, int anzahl);

        /**
         * @brief Ein bestimmtes Angebot von deinen Angeboten wird mithilfe der ID entfernt aus my_offer
         *
         * @param id
         */
        void remove_my_offer(int id);

        /**
         * @brief Get the my offer object
         *
         * @return std::map<int, Angebot>
         */
        std::map<int, Angebot> get_my_offer();

        /**
         * @brief Get the inventar object
         *
         * @return std::map<std::string,int>
         */
        std::map<std::string, int> get_inventar();

        /**
         * @brief Get the menge object
         *
         * @param ware
         * @return int
         */
        int get_menge(std::string ware);

        /**
         * @brief Get the my offer size object
         *
         * @return int
         */
        int get_my_offer_size();

        /**
         * @brief Get the berry object
         *
         * @return double
         */
        double get_berry() const;

        /**
         * @brief Get the pw object
         *
         * @return std::string
         */
        std::string get_pw();

        /**
         * @brief Get the name object
         *
         * @return std::string
         */
        std::string get_name();


    private:
        /**
         * @brief Vom Nutzer der Benutzername
         *
         */
        std::string benutzername;

        /**
         * @brief Vom Nutzer das Passwort
         *
         */
        std::string passwort;

        /**
         * @brief Alle gekauften Waren werden im Inventar gespeichert mit der Anzahl der Ware
         *
         */
        std::map<std::string, int> inventar;

        /**
         * @brief Die persönlich erstellten Angebote vom Markt werden hier gespeichert
         *
         */
        std::map<int, Angebot> my_offers;

        /**
         * @brief Die Währung Berry
         *
         */
        double berry;
    };
}

#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "../include/Angebot.hpp"

namespace Handelsplatz{

    class Nutzer
    {
        public:
            Nutzer(std::string benutzername, std::string passwort);
            double get_berry() const;
            void set_berry(double betrag);
            void sub_balance(double betrag, int menge);
            void add_balance(double betrag, int menge);
            bool find_ware(std::string ware);
            void add(const std::string& handelsgut, int anzahl);
            void add_for_delete(int ID);
            void remove(const std::string& handelsgut, int anzahl);
            void remove_my_offer(int id);
            int get_menge(std::string ware);
            void offer_einfügen(std::pair<int,Angebot> paar);
            int get_my_offer_size();
            bool find_my_offer(int id);
            std::map<int, Angebot> get_my_offer();
            std::map<std::string,int> get_inventar();
            std::string get_pw();
            std::string get_name();

            
        private:
            std::string benutzername;
            std::string passwort;
            std::map<std::string, int> inventar;
            std::map<int, Angebot> my_offers;
            double berry;
    };
}

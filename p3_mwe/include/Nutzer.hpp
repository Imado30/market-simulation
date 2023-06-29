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
            int get_berry() const;
            void set_berry(int betrag);
            bool find_ware(std::string ware);
            void add(const std::string& handelsgut, int anzahl);
            void remove(const std::string& handelsgut, int anzahl);
            void remove_my_offer(int id);
            int get_menge(std::string ware);
            void offer_einfügen(std::pair<int,Angebot> paar);
            int get_my_offer_size();
            bool find_my_offer(int id);
            std::map<int, Angebot> get_my_offer();
            std::map<std::string,int> get_inventar();
            std::string get_pw();

            
        private:
            std::string benutzername;
            std::string passwort;
            std::map<std::string, int> inventar;
            std::map<int, Angebot> my_offers;
            int berry;
    };
}

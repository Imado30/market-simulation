#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <../include/Angebot.hpp>
namespace Handelsplatz{

    class Nutzer{
        private:
            std::map<std::string, int> inventar;
            int berry;
            std::string benutzername;
            std::string passwort;
            std::map<int, Angebot> my_offers;

        public:

            Nutzer(std::string benutzername, std::string passwort);

            int get_berry() const;  

            void set_berry(int betrag);

            void add(const std::string& handelsgut, int anzahl);

            void remove(const std::string& handelsgut, int anzahl);

            std::string get_pw();

            void remove_my_offer(int id);

            int get_menge(std::string ware);

            void offer_einfügen(std::pair<int,Angebot> paar);

            int get_my_offer_size();

            bool find_my_offer(int id);

            std::map<int, Angebot> get_my_offer();

            std::map<std::string,int> get_inventar();

            bool find_ware(std::string ware);



    };
}

#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <string>

namespace Handelsplatz{

    class Nutzer{
        private:
            std::map<std::string, int> inventar;
            int berry;
            std::string benutzername;
            std::string passwort;
        public:

        Nutzer(std::string benutzername, std::string passwort);
        int get_berry() const;
        void set_berry(int betrag);
        void add(const std::string& handelsgut, int anzahl);
        void remove(const std::string& handelsgut, int anzahl);

        std::string get_pw();


    };
}

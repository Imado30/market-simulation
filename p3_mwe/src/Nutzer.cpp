#include <../include/Nutzer.hpp>
#include <iostream>
#include <string>
#include <map>

namespace Handelsplatz{


    Nutzer::Nutzer(std::string benutzername, std::string passwort)
    : benutzername(benutzername), passwort(passwort){}

    int Nutzer::get_berry() const {
        return berry;
    }

    void Nutzer::set_berry(int betrag){
        berry = betrag;
    }

    void Nutzer::add(const std::string& handelsgut, int anzahl) {
        inventar[handelsgut] += anzahl;
    }

    void Nutzer::remove(const std::string& handelsgut, int anzahl) {
        if (inventar.find(handelsgut) != inventar.end()) {
            if (inventar[handelsgut] >= anzahl) {
                inventar[handelsgut] -= anzahl;
            } else {
                std::cout << "Nicht genug " << handelsgut << " im Inventar!" << std::endl;
            }
        } else {
            std::cout << "Handelsgut " << handelsgut << " nicht im Inventar!" << std::endl;
        }
    }

    std::string Nutzer::get_pw(){
        return passwort;
    }


}



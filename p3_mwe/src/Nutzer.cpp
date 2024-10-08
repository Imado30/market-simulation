#include <../include/Nutzer.hpp>
#include <iostream>
#include <string>
#include <map>

namespace Handelsplatz
{

    Nutzer::Nutzer(std::string name, std::string pw) : benutzername(name), passwort(pw), berry(100000) {}

    double Nutzer::get_berry() const
    {
        return berry;
    }

    void Nutzer::set_berry(double betrag)
    {
        berry = betrag;
    }

    void Nutzer::add(const std::string &handelsgut, int anzahl)
    {
        inventar[handelsgut] += anzahl;
    }

    std::pair<std::string, int> Nutzer::add_for_delete(int ID)
    {
        auto item = my_offers.find(ID);
        auto angebot = item->second;

        std::string ware = angebot.get_warentyp();
        int anzahl = angebot.get_anzahl();

        return std::pair<std::string, int>(ware, anzahl);
    }

    void Nutzer::add_tuple(std::pair<std::string, int> paar)
    {
        std::string handelsgut = paar.first;
        int menge = paar.second;
        inventar[handelsgut] += menge;
    }

    void Nutzer::remove(const std::string &handelsgut, int anzahl)
    {
        if (inventar.find(handelsgut) != inventar.end())
        {
            if (inventar[handelsgut] >= anzahl)
            {
                inventar[handelsgut] -= anzahl;
            }
            else
            {
                std::cout << "Nicht genug " << handelsgut << " im Inventar!" << std::endl;
            }
        }
        else
        {
            std::cout << "Handelsgut " << handelsgut << " nicht im Inventar!" << std::endl;
        }
    }

    bool Nutzer::find_ware(std::string ware)
    {
        for (const auto &[handelsgut, menge] : inventar)
        {
            if (ware == handelsgut)
            {
                return true;
            }
        }
        return false;
    }

    int Nutzer::get_menge(std::string ware)
    {
        bool suche = Nutzer::find_ware(ware);
        if (suche == true)
        {
            auto item = inventar.find(ware);
            return item->second;
        }
        return 0;
    }

    void Nutzer::offer_einfügen(std::pair<int, Angebot> paar)
    {
        my_offers.insert(paar);
        std::cout << "Erfolgreich hinzugefügt" << std::endl;
    }

    bool Nutzer::find_my_offer(int id)
    {
        for (const auto &[id_, angebot] : my_offers)
        {
            if (id == id_)
            {
                return true;
            }
        }
        return false;
    }

    void Nutzer::remove_my_offer(int id)
    {
        my_offers.erase(id);
    }

    std::map<int, Angebot> Nutzer::get_my_offer()
    {
        return my_offers;
    }

    std::map<std::string, int> Nutzer::get_inventar()
    {
        return inventar;
    }

    std::string Nutzer::get_pw()
    {
        return passwort;
    }

    int Nutzer::get_my_offer_size()
    {
        return my_offers.size();
    }

    void Nutzer::sub_balance(double betrag, int menge)
    {
        berry = berry - (menge * betrag);
    }

    void Nutzer::add_balance(double betrag, int menge)
    {
        berry = berry + (menge * betrag);
    }

    std::string Nutzer::get_name()
    {
        return benutzername;
    }
}
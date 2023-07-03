#include "../include/Markt.hpp"
#include <bits/stdc++.h>
#include <iostream>

namespace Handelsplatz
{

    Markt::Markt() : max_o_id(100000)
    {
        for (int i = 0; i++; i < max_o_id)
        {
            offer_ids.push(i);
        }
    }

    std::vector<Angebot> Markt::get_offer()
    {
        std::vector<Angebot> out;
        for (int i = 0; i < max_o_id; i++)
        {
            if (offers.find(i) != offers.end())
            {
                out.push_back(offers.at(i));
            }
        }
        return out;
    }

    std::map<int, Angebot> Markt::get_offers()
    {
        return offers;
    }

    void Markt::add_offer_ids()
    {
        for (int i = max_o_id; i < max_o_id * 2; i++)
        {
            offer_ids.push(i);
        }
        max_o_id *= 2;
    }

    std::pair<int, Angebot> Markt::create_offer(std::string name, std::string ware, int menge, double preis)
    {
        Nutzer n = user.at(name);
        Angebot a(ware, menge, preis);

        if (offer_ids.empty())
        {
            add_offer_ids();
        }

        int id = offer_ids.front();
        offer_ids.pop();

        offers.insert(std::pair<int, Angebot>(id, a));
        owner.insert(std::pair<int, Nutzer>(id, n));                // owner wird hinzugefügt

        std::cout << offers.size() << std::endl;
        std::cout << "Angebot erfolgreich erstellt" << std::endl;
        return std::pair<int, Angebot>(id, a);
    }

    Nutzer Markt::get_user(std::string name)
    {
        Nutzer n = user.at(name);
        return n;
    }

    void Markt::delete_offer(int id)
    {
        offers.erase(id);
    }

    Nutzer Markt::create_user(std::string name, std::string pw)
    {
        if (user.find(name) != user.end())
        {
            throw std::logic_error("Benutzername bereits vergeben");
        }

        Nutzer n(name, pw);
        user.insert(std::pair<std::string, Nutzer>(name, n));
        return n;
    }
    // nicht klappt, nutzer erstllen umschreiben, sodass der erstellte Nutzer
    // als Rückgabetyp zurückgibt, edit user aufrufen,
    // kriegt den Nutzer aus create_user als Parameter

    void Markt::edit_user(std::string name, Nutzer n)
    {
        user.at(name) = n;
    }

    void Markt::edit_my_offer(Nutzer n, std::pair<int, Angebot> paar)
    {
        int id = paar.first;
        Angebot a = paar.second;
        // n.my_offers.at(id) = a;
        // n.offers.at(id) = a;
    }

    int Markt::get_size_user()
    {
        return user.size();
    }

    bool Markt::auth(std::string name, std::string pw)
    {
        if (user.at(name).get_pw() == pw)
        {
            return true;
        }
        return false;
    }

    int Markt::get_size_offers()
    {
        return offers.size();
    }

    void Markt::kursverlauf_berechnen(std::string handelsgut){
        double tendenz = 0.1;
        double streuung = 0.2;
        double dt = 0.01;
        double start = 5000;
        int anzahl = 10;

        double sqdt = std::sqrt(dt);
        int kurs[anzahl];
        kurs[0] = start;
        for (int i = 0; i < anzahl - 1; i++) {
            double Y = 2.0 * (static_cast<double>(std::rand()) / RAND_MAX) - 1.0;
            kurs[i+1] = kurs[i] * (1 + tendenz * dt + streuung * sqdt * Y);
        }

        // Runden auf 2 Dezimalstellen
        double gerundeterPreis = std::round(kurs[anzahl - 1] * 100) / 100;
        preise[handelsgut] = gerundeterPreis;
        }


    void Markt::update_all()
    {
        for (auto handelsgut : handelsgueter)
        {
            kursverlauf_berechnen(handelsgut);
        }
    }

    int Markt::get_preis(std::string key)
    {
        if (preise.find(key) != preise.end())
        {
            return preise[key];
        }
        else
        {
            return -1; // gibt -1 zurück, um anzuzeigen, dass der Schlüssel nicht vorhanden ist
        }
    }

    int Markt::offer_bearbeiten(int id, int anzahl)
    {
        if (offers.find(id) != offers.end())
        {
            auto item = offers.find(id);
            auto angebot = item->second;

            if (angebot.get_anzahl() > anzahl)
            {
                int menge = angebot.get_anzahl();
                int new_anzahl = menge - anzahl;
                offers.erase(id);
                return new_anzahl;
            }
        }
        else
        {
            std::cout << "Die ID wurde nicht im Markt gefunden" << std::endl;
        }
        return 0;
    }

    void Markt::accept_offer(std::string name, int id)
    {
        Angebot a = offers.at(id);
        int anzahl = a.get_anzahl();
        double preis = a.get_preis();
        std::string ware = a.get_warentyp();

        Nutzer n = user.at(name);

        if (n.get_berry() < preis * anzahl)
        {
            throw std::logic_error("you're broke :'( ");
        }

        n.add(ware, anzahl);
        n.sub_balance(preis, anzahl);

        Nutzer n2 = get_owner(id);
        n2.add_balance(preis, anzahl);
        offers.erase(id);

        n2.remove_my_offer(id);
        owner.erase(id);
        offer_ids.push(id);

        user.at(name) = n;
        user.at(n2.get_name()) = n2;
    }

    Nutzer Markt::get_owner(int id)
    {
        return owner.at(id);
    }

    void Markt::sell(std::string name, std::string ware, int menge)
    {
        Nutzer n = user.at(name);
        if (menge > n.get_menge(ware))
        {
            throw std::logic_error("");
        }
        n.remove(ware, menge);

        double value = preise.at(ware) * menge;
        double fee = 0.9;
        n.set_berry(n.get_berry() + value * fee);

        user.at(name) = n;
    }

    void Markt::buy(std::string name, std::string ware, int menge)
    {

        Nutzer n = user.at(name);
        double cost = menge * preise.at(ware) * 1.1;

        if (n.get_berry() < cost)
        {
            throw std::logic_error("User cant afford transaction");
        }

        n.add(ware, menge);
        n.set_berry(n.get_berry() - cost);

        user.at(name) = n;
    }

}

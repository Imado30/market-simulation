#include "../include/Markt.hpp"
#include <iostream>
#include <map>
#include <exception>

namespace Handelsplatz{

    Markt::Markt():max_o_id(100000){
        for (int i=0; i++; i<max_o_id){
            offer_ids.push(i);
        }
    }

    std::map<int, Angebot> Markt::get_offers(){
        return offers;
    }

    Nutzer Markt::create_user(std::string name, std::string pw){
        if (user.find(name)!=user.end()){
            throw std::logic_error("Benutzername bereits vergeben");
        }
        Nutzer n(name, pw);
        user.insert(std::pair<std::string, Nutzer>(name,n));
        return n;
    }

    void Markt::edit_user(std::string name, Nutzer n){
        user.at(name)=n;
    }

    int Markt::get_size_user(){
        return user.size();
    }

    bool Markt::auth(std::string name, std::string pw){
        if (user.at(name).get_pw()==pw){
            return true;
        }
        return false;
    }

    void Markt::add_offer_ids()
    {
        for (int i= max_o_id; i<max_o_id*2; i++){
            offer_ids.push(i);
        }
        max_o_id*=2;
    }

    void Markt::delete_offer(std::string name, std::string pw, int id)
    {
        // das angebot muss zurück ins inventar getan werden
        Nutzer n(name, pw);
        //vorher überprüfen ob id in my_offers der Nutzer Klasse ist
        n.remove_my_offer(id);
    }

    void Markt::edit_my_offer(Nutzer n, std::pair<int,Angebot> paar)
    {
        int id = paar.first;
        Angebot a = paar.second;
        //n.my_offers.at(id) = a;
        //n.offers.at(id) = a;
    }

        int Markt::get_size_offers()
    {
        return offers.size();
    }

    Nutzer Markt::get_user(std::string name)
    {
        Nutzer n = user.at(name);
        return n;
    }

    std::pair<int,Angebot> Markt::create_offer(std::string name, std::string ware, int menge, double preis)
    {   
        Nutzer n = user.at(name);
        Angebot a(ware, menge, preis);

        if (offer_ids.empty()){
            add_offer_ids();
        }

        int id = offer_ids.front();
        offer_ids.pop();
        
        offers.insert(std::pair<int,Angebot>(id,a));

        std::cout << offers.size() << std::endl;
        //n.offer_einfügen(id, a);
        n.remove(ware, menge);
        std::cout << "Angebot erfolgreich erstellt" << std::endl;
        return std::pair<int,Angebot>(id,a);
    }

}
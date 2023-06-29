#include "../include/Markt.hpp"
#include <bits/stdc++.h>
#include <iostream>

namespace Handelsplatz{

    std::vector<Angebot> Markt::get_offer(){
        std::vector<Angebot> out;
        for(int i=0; i<max_o_id; i++){
            if (offers.find(i)!=offers.end()){
                out.push_back(offers.at(i));
            }
        }
        return out;
    }

    void Markt::add_offer_ids()
    {
        for (int i= max_o_id; i<max_o_id*2; i++){
            offer_ids.push(i);
        }
        max_o_id*=2;
    }


    std::pair<int,Angebot> Markt::create_offer(std::string name, std::string ware, int menge, double preis)
    {   
        Nutzer n = user.at(name);
        Angebot a(ware, menge, preis);
        int id = offer_ids.front();
        offer_ids.pop();
        offers.insert(std::pair<int,Angebot>(id,a));
        std::cout << offers.size() << std::endl;
        //n.offer_einfügen(id, a);
        n.remove(ware, menge);
        std::cout << "Angebot erfolgreich erstellt" << std::endl;
        return std::pair<int,Angebot>(id,a);
    }

    Nutzer Markt::get_user(std::string name)
    {
        Nutzer n = user.at(name);
        return n;
    }

    void Markt::delete_offer(std::string name, std::string pw, int id)
    {
        // das angebot muss zurück ins inventar getan werden
        Nutzer n(name, pw);
        //vorher überprüfen ob id in my_offers der Nutzer Klasse ist
        n.remove_my_offer(id);
    }

    Nutzer Markt::create_user(std::string name, std::string pw)
    {
        Nutzer n(name, pw);
        user.insert(std::pair<std::string, Nutzer>(name,n));
        return n;
    }
    //nicht klappt, nutzer erstllen umschreiben, sodass der erstellte Nutzer 
    //als Rückgabetyp zurückgibt, edit user aufrufen, 
    //kriegt den Nutzer aus create_user als Parameter

    void Markt::edit_user(std::string name, Nutzer n)
    {
        user.at(name)=n;
    }

    void Markt::edit_my_offer(Nutzer n, std::pair<int,Angebot> paar)
    {
        int id = paar.first;
        Angebot a = paar.second;
        //n.my_offers.at(id) = a;
        //n.offers.at(id) = a;
    }

    int Markt::get_size_user(){
      return user.size();
    }

    bool Markt::auth(std::string name, std::string pw)
    {
        if (user.at(name).get_pw()==pw){
            return true;
        }
        return false;
    }

    int Markt::get_size_offers()
    {
        return offers.size();
    }
}
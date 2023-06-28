#include "../include/Markt.hpp"
#include <iostream>
#include <map>

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

    Nutzer Markt::create_user(std::string name, std::string pw){
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

}
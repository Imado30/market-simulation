#include "../include/Markt.hpp"
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
}
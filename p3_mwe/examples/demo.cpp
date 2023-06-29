#include <iostream>
#include "../include/Markt.hpp"
#include "../include/Angebot.hpp"
#include "../include/Nutzer.hpp"

// clang++ -std=c++17 -I./include src/Nutzer.cpp src/Angebot.cpp src/Markt.cpp examples/demo.cpp -o test

int main()
{
    Handelsplatz::Markt x;

    Handelsplatz::Nutzer n("Hi","lol");
    Handelsplatz::Angebot a("gold",4,20);
    //n.offer_einfügen(12345, a);
    n.get_my_offer();
}
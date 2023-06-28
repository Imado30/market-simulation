#pragma once
#include "../include/Angebot.hpp"
#include "../include/Nutzer.hpp"
#include <iostream>
#include <map>
#include <vector>

namespace Handelsplatz{

    class Markt{
        public:
            //void create_offer(std::string name, std::string pw, std::string ware, int menge, double preis);

            std::vector<Angebot> get_offer();

            //void delete_offer(std::string name, std::string pw, int id);

            //void accept_offer(std::string name, std::string pw, int id);

            
            //Funktionen zum Handeln mit dem Markt 
            //void sell(std::string name, std::string pw, std::string ware, int menge);

            //void buy(std::string name, std::string pw, std::string ware, int menge);

            Nutzer create_user(std::string name, std::string pw);

            void edit_user(std::string name, Nutzer n);

            int get_size_user();

            bool auth(std::string name, std::string pw);

        private:
            /**
             * @brief speichert die Nutzer mit key: Benutzername, value: zugehöriges Nutzerobjekt
             * 
             */
            std::map<std::string, Nutzer> user;

            /**
             * @brief speichert die Angebote mit Key: ID des Angebots, value: zugehöriges Angebot (Gedanke ist, dass das Speichern mit ID das Löschen vereinfacht)
             * 
             */
            std::map<int, Angebot> offers;

            /**
             * @brief key: Handelsgut, value: value-struct(speichert Preise und Variablen zur Preisberechnung)
             * 
             */
            //std::map<std::string, value> preise;

            std::vector<int> offer_ids;

            int max_o_id;
    };


}
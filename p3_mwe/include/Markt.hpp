#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include "../include/Nutzer.hpp"
#include "../include/Angebot.hpp"

namespace Handelsplatz{

    class Markt{
        public:
            std::pair<int,Angebot> create_offer(std::string name, std::string ware, int menge, double preis);

            std::vector<Angebot> get_offer();

            void delete_offer(std::string name, std::string pw, int id);

            void accept_offer(std::string name, std::string pw, int id);

            //Funktionen zum Handeln mit dem Markt 
            void sell(std::string name, std::string pw, std::string ware, int menge);

            void buy(std::string name, std::string pw, std::string ware, int menge);

            void add_offer_ids();

            Nutzer create_user(std::string name, std::string pw);

            Nutzer get_user(std::string name);

            void edit_user(std::string name, Nutzer n);

            void edit_my_offer(Nutzer n, std::pair<int,Angebot> paar);

            int get_size_user();

            bool auth(std::string name, std::string pw);

            int get_size_offers();

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

            std::queue<int> offer_ids;

            int max_o_id;

    };
}